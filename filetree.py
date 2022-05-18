import os
import json

def path_to_dict(path):
    d = {'name': os.path.basename(path)}
    if os.path.isdir(path):
        # d['type'] = "directory"
        d['children'] = [path_to_dict(os.path.join(path,x)) for x in os.listdir\
(path)]
    # else:
    #     d['type'] = "file"
    return d

path = "/media/sigmind/watchcam-data/all_high_way_concatenated_mp4"
for dirpath, dirnames, filenames in os.walk(path):
    directory_level = dirpath.replace(path, "")
    directory_level = directory_level.count(os.sep)
    indent = " " * 4
    print("{}{}/".format(indent*directory_level, os.path.basename(dirpath)))

    for f in filenames:
        print("{}{}".format(indent*(directory_level+1), f))

# x = path_to_dict('/media/sigmind/watchcam-data/all_high_way_concatenated_mp4')
# # print(x['children'][1]['children'][0]['children'])
# print(x)