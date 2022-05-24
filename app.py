import os
import shutil
import cv2
import json
import time
import requests
import glob
import os.path
from os import path
from flask import Flask, render_template, flash, url_for, redirect, request
from flask_wtf import FlaskForm
from wtforms import FileField,MultipleFileField, SubmitField
from werkzeug.utils import secure_filename
from wtforms.validators import InputRequired
from collections import Iterable
import settings



app = Flask(__name__)
app.config['SECRET_KEY'] = 'supersecretkey'
app.config['UPLOAD_FOLDER'] = settings.uploadFolder

class UploadFileForm(FlaskForm):
    # file = FileField("File", validators=[InputRequired()])
    file = MultipleFileField('File(s) Upload',validators=[InputRequired()])
    submit = SubmitField("Upload File")

@app.route('/', methods=['GET',"POST"])
@app.route('/home', methods=['GET',"POST"])
def home():
    form = UploadFileForm()
    filelist= [file for file in os.listdir(app.config['UPLOAD_FOLDER']) if file.endswith(".mp4")]
    filelist.sort()
    if form.validate_on_submit():
        uploadedFilelist = form.file.data # First grab the file
        print(uploadedFilelist)
        try:
            for file in uploadedFilelist:
                if(secure_filename(file.filename).endswith(".mp4")):
                    save_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),app.config['UPLOAD_FOLDER'],secure_filename(file.filename))
                    file.save(save_path) # Then save the file
                    flash(f'{secure_filename(file.filename)} uploaded successfully!', 'success')
                    filelist = [file for file in os.listdir(
                        app.config['UPLOAD_FOLDER']) if file.endswith(".mp4")]
                    filelist.sort()
                else:
                    flash(f'Failed to upload!\nPlease upload a video file.', 'danger')
        except:
            flash('Upload failed!', 'danger')
            
        # return render_template('index.html', form=form, filelist=[file for file in os.listdir(app.config['UPLOAD_FOLDER']) if file.endswith(".mp4")], apiname=['home'])
    return render_template('index.html', form=form, filelist=filelist , apiname=['home'])

@app.route('/queue', methods=['GET',"POST"])
def queue():
    def flatten(lis):
     for item in lis:
         if isinstance(item, Iterable) and not isinstance(item, str):
             for x in flatten(item):
                 yield x
         else:        
             yield item
    form = UploadFileForm()
    allfiles = []
    import os
    
    rootdir = settings.rootdir
    for file in os.listdir(rootdir):
        d = os.path.join(rootdir, file)
        if os.path.isdir(d):
            filelist= [filez + '-' + os.path.basename(d) for filez in os.listdir(d) if os.path.isdir(os.path.join(d,filez))]
            allfiles.append(filelist)
    allfiles = list(flatten(allfiles))
    # allfiles.sort()
    allfiles.sort(key = lambda x: (x.split('-')[1], x.split('-')[0]))
    # print(allfiles)
    if form.validate_on_submit():
        file = form.file.data # First grab the file
        try:
            if(secure_filename(file.filename).endswith(".mp4")):
                save_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),app.config['UPLOAD_FOLDER'],secure_filename(file.filename))
                file.save(save_path) # Then save the file
                flash(f'{secure_filename(file.filename)} uploaded successfully!', 'success')
            else:
                flash(f'Failed to upload!\nPlease upload a video file.', 'danger')
        except:
            flash('Upload failed!', 'danger')
        # return render_template('queue.html', form=form, filelist=allfiles, apiname=['queue'])
    return render_template('queue.html', form=form, filelist=allfiles, apiname=['queue'])

@app.route('/firstFrame/<string:videoClicked>', methods=["GET","POST"])
def firstFrame(videoClicked):
    videoClicked = json.loads(videoClicked)
    video_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),app.config['UPLOAD_FOLDER'],videoClicked)
    def getFirstFrame(videofile):
        vidcap = cv2.VideoCapture(videofile)
        success, image = vidcap.read()
        if success:
            image_name = videoClicked + "_first_frame.jpg"
            save_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),'static/', 'frames/', image_name)
            cv2.imwrite(save_path, image)  # save frame as JPEG file
        return image_name
    try:
        image_name = getFirstFrame(video_path)
        time.sleep(0.05)
        return render_template('firstFrame.html', image_path = image_name, videoClicked = videoClicked)
    except:
        pass

    return redirect('/')

@app.route('/firstFrameCam/<string:videoClicked>', methods=["GET","POST"])
def firstFramCam(videoClicked):

    def getFirstFrame(videofile):
        vidcap = cv2.VideoCapture(videofile)
        success, image = vidcap.read()
        if success:
            image_name = videoClicked + "_first_frame.jpg"
            save_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),'static/', 'frames/', image_name)
            print(save_path)
            cv2.imwrite(save_path, image)  # save frame as JPEG file
        return image_name

    videoClicked = json.loads(videoClicked)
    try:
        videosplit = videoClicked.split('-')
        cam = videosplit[0]
        loc = videosplit[1]

        rootpath = settings.rootdir
        video_dir = os.path.join(rootpath, loc, cam)
        filelist= [file for file in os.listdir(video_dir) if file.endswith(".mp4")]
        video_path = os.path.join(video_dir, filelist[0])
    except:
        video_path = None
    if(video_path == None):
        flash(f'NO VIDEOS FOUND in {videoClicked}', 'danger')

    else:

        image_name = getFirstFrame(video_path)
        time.sleep(0.05)
        return render_template('firstFrameCam.html', image_path = image_name, videoClicked = videoClicked)
    return redirect('/queue')

@app.route('/analyze/<string:points>', methods=['GET',"POST"])
def analyze(points):
    Points = json.loads(points)
    vFile = Points['videoFile']
    s1 = Points['Exit_Dir'] + Points['Exit_Line']
    s2 = Points['Entry_Dir'] + Points['Entry_Line']

    a_file = open("static/cfgs/cfg_main.txt", "r")
    list_of_lines = a_file.readlines()
    ex = list_of_lines.index('line-crossing-Exit=\n')
    en = list_of_lines.index('line-crossing-Entry=\n')

    list_of_lines[ex] = 'line-crossing-Exit=' + s1 + '\n'
    list_of_lines[en] = 'line-crossing-Entry=' + s2 + '\n'

    configFile = settings.configFile

    a_file = open(configFile, "w")
    a_file.writelines(list_of_lines)
    a_file.close()

    source = f"file://{os.getcwd()}/static/files/{vFile}"
    survey = settings.survey

    analysis_dir = os.path.join(settings.survey,'static','files', vFile[:-4])
    print(analysis_dir)

    flash(f'{vFile} started to analyze!', 'analyze')
    multistreamCommand = settings.multistreamCommand
    cmd = f"{multistreamCommand} {source} {survey}; cd ../..;"
    os.system(cmd)

    analysis_dir = os.path.join(settings.survey, 'static', 'files', vFile[:-4])
    print(analysis_dir)
    videoWiseReportCommand = settings.videoWiseReportCommand
    cmd = f"{videoWiseReportCommand} {analysis_dir}; cd ../..;"
    os.system(cmd)

    return redirect('/')

@app.route('/analyzeCam/<string:points>', methods=['GET',"POST"])
def analyzeCam(points):
    Points = json.loads(points)
    vFile = Points['videoFile']

    videosplit = vFile.split('-')
    cam = videosplit[0]
    loc = videosplit[1]
    rootpath = settings.rootdir
    video_dir = os.path.join(rootpath, loc, cam)
    print(video_dir)
    absfile = []
    for file in os.listdir(video_dir):
        if file.endswith(".mp4"):
            s = 'file://' + video_dir + '/' + file
            absfile.append(s)

    s1 = Points['Exit_Dir'] + Points['Exit_Line']
    s2 = Points['Entry_Dir'] + Points['Entry_Line']

    a_file = open("static/cfgs/cfg_main.txt", "r")
    list_of_lines = a_file.readlines()
    ex = list_of_lines.index('line-crossing-Exit=\n')
    en = list_of_lines.index('line-crossing-Entry=\n')

    list_of_lines[ex] = 'line-crossing-Exit=' + s1 + '\n'
    list_of_lines[en] = 'line-crossing-Entry=' + s2 + '\n'

    configFile = settings.configFile

    a_file = open(configFile, "w")
    a_file.writelines(list_of_lines)
    a_file.close()

    survey = settings.surveyCameraWise

    flash(f'{vFile} started to analyze!', 'analyze')
    for source in absfile:
        multistreamCommand = settings.multistreamCommand
        cmd = f"{multistreamCommand} {source} {survey}; cd ../..;"
        os.system(cmd)
    camWiseReportCommand = settings.cameraWiseReportCommand
    cmd = f"{camWiseReportCommand} {video_dir}; cd ../..;"
    os.system(cmd)

    return redirect('/queue')

if __name__ == '__main__':
    app.run(debug=True)