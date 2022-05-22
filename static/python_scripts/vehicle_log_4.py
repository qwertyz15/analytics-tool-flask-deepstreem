# /media/sigmind/watchcam-data/survey_video_extract_flask/Location24/Cam2/141

from genericpath import exists
import glob
import os
import json
import sys
import pandas as pd
import numpy as np


def createDF():
    columns = ["Direction", "heavytruck", "lighttruck", "midtruck", "bigbus", "minibus", "microbus",
               "car", "threewheeler", "utility", "midtruck", "minibus", "motorbike", "bicycle", "undefined"]
    directions = ['Entry', 'Exit']
    df = pd.DataFrame(columns=columns)
    df['Direction'] = directions
    return df


# rootpath  = sys.argv[1]
rootpath = '/media/sigmind/watchcam-data/survey_video_extract_flask/Location24/Cam2/141'
rootdir = os.path.dirname(rootpath)
rootbase = os.path.basename(rootpath)
camdir = os.path.dirname(rootdir)
cambase = os.path.basename(rootdir)
locbase = os.path.basename(camdir)
print(rootbase, cambase, locbase)
# print(locBase)
# try:
#     os.mkdir(f"../Reports/{locBase}")
# except:
#     pass

df = createDF()

lpath = rootpath
files = glob.glob(lpath + '/**/*.jpg', recursive=True)
log = dict()

new_files = []
for f in files:
    x = os.path.dirname(f)
    new_files.append(x)
new_files = set(new_files)
new_files = list(new_files)
new_files.sort()

for x in new_files:

    vehicle = os.path.basename(x)
    path, dirs, fil = next(os.walk(x))
    file_count = len(fil)

    directionDir = os.path.dirname(x)
    directionBase = os.path.basename(directionDir)


    cond1 = (df['Direction'] == 'Entry')
    cond2 = (df['Direction'] == 'Exit')

    total_count = file_count
    if(directionBase == 'Entry'):
        df.loc[cond1, vehicle] = str(total_count)
    elif(directionBase == 'Exit'):
        df.loc[cond2, vehicle] = str(total_count)



df.rename(columns={"undefined": "others", "car": "sedan"}, inplace=True)
df.replace(np.nan, 0, inplace=True)
df.set_index(['Direction'], inplace=True)
df = df.T
df.index.names = ['Vehicles']
# print(df)
saveFile = f'../Single_Video_Reports/{rootbase}_{cambase}_{locbase}.xlsx'
# df.to_csv('logex.csv')
df.to_excel(saveFile)
del df
