import os
import shutil
import cv2
import json
import time
import requests
from flask import Flask, render_template, flash, url_for, redirect, request
from flask_wtf import FlaskForm
from wtforms import FileField, SubmitField
from werkzeug.utils import secure_filename
from wtforms.validators import InputRequired



app = Flask(__name__)
app.config['SECRET_KEY'] = 'supersecretkey'
app.config['UPLOAD_FOLDER'] = 'static/files'

class UploadFileForm(FlaskForm):
    file = FileField("File", validators=[InputRequired()])
    submit = SubmitField("Upload File")

@app.route('/', methods=['GET',"POST"])
@app.route('/home', methods=['GET',"POST"])
def home():
    form = UploadFileForm()
    filelist= [file for file in os.listdir(app.config['UPLOAD_FOLDER']) if file.endswith(".mp4")]
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
            
        # return redirect(url_for('index.html'), form=form, filelist = filelist)
        return render_template('index.html', form=form, filelist = filelist)
    return render_template('index.html', form=form, filelist = filelist)

@app.route('/firstFrame/<string:videoClicked>', methods=["GET","POST"])
def firstFrame(videoClicked):
    videoClicked = json.loads(videoClicked)
    print('##########################')
    print(videoClicked)
    print('##########################')
    video_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),app.config['UPLOAD_FOLDER'],videoClicked)
    def getFirstFrame(videofile):
        vidcap = cv2.VideoCapture(videofile)
        success, image = vidcap.read()
        if success:
            image_name = videoClicked + "_first_frame.jpg"
            save_path = os.path.join(os.path.abspath(os.path.dirname(__file__)),'static/', 'frames/', image_name)
            print(save_path)
            cv2.imwrite(save_path, image)  # save frame as JPEG file
        return image_name
    image_name = getFirstFrame(video_path)
    print('------------------------')
    print(image_name)
    print('-------------------------')
    time.sleep(0.05)
    return render_template('firstFrame.html', image_path = image_name, videoClicked = videoClicked)
    # return '<p> first Frame </p>'

@app.route('/analyze/<string:points>', methods=['GET',"POST"])
# @app.route('/analyze', methods=['GET',"POST"])
def analyze(points):
    Points = json.loads(points)
    print('$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$')
    print(Points)
    vFile = Points['videoFile']
    print('$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$')
    s1 = Points['Exit_Dir'] + Points['Exit_Line']
    s2 = Points['Entry_Dir'] + Points['Entry_Line']

    a_file = open("static/cfgs/cfg_main.txt", "r")
    list_of_lines = a_file.readlines()
    ex = list_of_lines.index('line-crossing-Exit=\n')
    en = list_of_lines.index('line-crossing-Entry=\n')

    list_of_lines[ex] = 'line-crossing-Exit=' + s1 + '\n'
    list_of_lines[en] = 'line-crossing-Entry=' + s2 + '\n'

    save_cfg = 'static/cfgs/' + vFile + '.txt'

    a_file = open("static/analytics_tool/resources/cfg/flask.txt", "w")
    a_file.writelines(list_of_lines)
    a_file.close()

    source = f"file://{os.getcwd()}/static/files/{vFile}"
    survey = "/media/sigmind/watchcam-data/survey_video_extract_flask"
    # dest = f"/media/sigmind/watchcam-data/all_high_way_concatenated_mp4/Location_Flask/Cam1/{vFile}"

    # shutil.copyfile(source, dest)

    flash(f'{vFile} started to analyze!', 'analyze')
    cmd = f"cd static/deepstream-imagedata-multistream; python3 deepstream_imagedata-multistream_flask.py {source} {survey}; cd ../..;"
    os.system(cmd)


    
    # if(request.method == 'POST'):
    #     try:
    #         if(request.form['submit_button'] == 'analyze'):
    #             print(videoClicked)
    #             print("Analyze button is pressed")
    #             flash(f'{videoClicked} started to analyze!', 'analyze')
    #     except:
    #         pass

    # cmd = "cd ~; cd /home/sigmind/Documents/deepstream_sdk_v6.0.1_x86_64/opt/nvidia/deepstream/deepstream-6.0/sources/apps/deepstream_python_apps/apps/deepstream-imagedata-multistream; python3 run.py"
    # os.system(cmd)
    # return "Analyze started"
    # return render_template('index.html', form=form, filelist = filelist)
    return redirect('/')

if __name__ == '__main__':
    app.run(debug=True)