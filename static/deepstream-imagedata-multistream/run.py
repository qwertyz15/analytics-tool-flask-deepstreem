import subprocess
import os
import json

location = 'Location52'
root_dir = "/media/sigmind/watchcam-data/all_high_way_concatenated_mp4/" + location + "/"
try:
    os.remove(root_dir)
except:
    pass
DIR_PATHS = [root_dir + "Cam1", root_dir + "Cam2", root_dir + "Cam3", root_dir + "Cam4"]

#arr = [4][2]
save_path = '/media/sigmind/BigData/survey_video_extract/' + location +  '/finished_video.json'
saves = dict()
saves['Cam1'] = []
saves['Cam2'] = []
saves['Cam3'] = []
saves['Cam4'] = []
NO_VIDEOS = False


num_of_vids_in_srcs = []
vids_in_srcs = []
srcs_have_vid = []
num_of_srcs = len(DIR_PATHS)

def search_in_path(path, extension):
    videos = []
    print("Searching for videos in {}".format(path))
    for root, directories, files in os.walk(path):
        for file in files:
            if file.endswith(extension):
                videos.append(os.path.join(root, file))
    num_of_vids = len(videos)
    print("Videos found {}".format(num_of_vids))
    return num_of_vids, videos
    

for path in DIR_PATHS:
    num_of_vids, videos = search_in_path(path, ".mp4")

    if num_of_vids > 0 : has_vid = True
    else: has_vid = False

    num_of_vids_in_srcs.append(num_of_vids)
    vids_in_srcs.append(videos)
    srcs_have_vid.append(has_vid)


while not NO_VIDEOS:
    uri_arg_string = " "

    for src_number in range(num_of_srcs):
        num_of_vids = num_of_vids_in_srcs[src_number]
        has_vid = srcs_have_vid[src_number]
        videos = vids_in_srcs[src_number]

        if num_of_vids > 0 :
            uri_arg_string = uri_arg_string + "file://" + videos[num_of_vids-1] + " "
            num_of_vids = num_of_vids-1
            has_vid = True
        else:
            has_vid = False

        num_of_vids_in_srcs[src_number] = num_of_vids
        srcs_have_vid[src_number] = has_vid
    
    if any(srcs_have_vid):
        print(uri_arg_string)


        cmd = "python3 deepstream_imagedata-multistream.py" + uri_arg_string + " /media/sigmind/watchcam-data/survey_video_extract"
        print("Playing files: {}".format(uri_arg_string))
        process = subprocess.Popen(cmd, shell=True)
        process.wait()


    
    else:
        NO_VIDEOS = True
        print("No more files to analyze. Ending ...")
        break

    z = z = uri_arg_string.split(" file://")
    z = z[1:]
    for cam in z:
        timeslot = os.path.basename(cam)
        timeslot = timeslot[:-4]
        camera = os.path.dirname(cam)
        camera = os.path.basename(camera)
        saves[camera].append(timeslot)

    try:
        # f = open(save_path, "a")
        # argString = uri_arg_string.replace(" file://", '\n')
        # f.write(argString)
        # f.close()
        with open(save_path, 'a') as convert_file:
            convert_file.write(json.dumps(saves))
    except:
        pass

print("Analysis Completed")



