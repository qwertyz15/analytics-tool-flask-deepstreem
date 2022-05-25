from genericpath import exists
import glob
import os
import json
import sys
import pandas as pd
import numpy as np
# import ../../settings


def createDF():
    time = ["08.00-08.15", "08.15-08.30", "08.30-08-45", "08.45-09.00", "09.00-09.15", "09.15-09.30", "09.30-09-45", "09.45-10.00", "13.00-13.15", "13.15-13.30", "13.30-13-45", "13.45-14.00", "14.00-14.15", "14.15-14.30", "14.30-14-45", "14.45-15.00", "19.00-19.15", "19.15-19.30", "19.30-19-45", "19.45-20.00", "20.00-20.15", "20.15-20.30", "20.30-20-45", "20.45-21.00"]

    idx = ["081","082","083","084","091","092","093","094","131","132","133","134","141","142","143","144","191","192","193","194","201","202","203","204"]
    times = []
    idxs = []
    dirs = []
    for  i in range(0, len(time)):
        times.append(time[i])
        times.append(time[i])
        idxs.append(idx[i])
        idxs.append(idx[i])
        dirs.append("Entry")
        dirs.append("Exit")

    columns  = ["Time", "Direction", "heavytruck", "lighttruck", "midtruck", "bigbus", "minibus", "microbus", "car", "threewheeler", "utility", "midtruck", "minibus", "motorbike", "bicycle", "undefined"]

    df = pd.DataFrame(index = idxs, columns = columns)
    df['Time'] = times
    df['Direction'] = dirs
    return df
# df.replace(np.nan, 0, inplace=True)


rootpath  = sys.argv[1]
rootdir = os.path.dirname(rootpath)
rootbase = os.path.basename(rootpath)
locBase = os.path.basename(rootdir)
# print(locBase)
try:
    os.mkdir(f"../Reports/{locBase}")
except:
    pass

df = createDF()

lpath = rootpath
# print(lpath)
# files = [f for f in glob.glob(lpath + "**/*.jpg", recursive=True)]
files = glob.glob(lpath + '/**/*.jpg', recursive=True)
# files = set(files)
# files = list(files)
# print(len(files))
# print(files)
log = dict()

new_files = []
for f in files:
    # print(f)
    # print(os.path.basename(f))
    x = os.path.dirname(f)
    new_files.append(x)
new_files = set(new_files)
new_files = list(new_files)
new_files.sort()
# print(new_files)

# new_files = []
for x in new_files:
    # print(f)
    # print(os.path.basename(f))
    # x = os.path.dirname(f)
    # print(x)
    vehicle = os.path.basename(x)
    path, dirs, fil = next(os.walk(x))
    file_count = len(fil)
    # print(file_count)
    directionDir = os.path.dirname(x)
    directionBase = os.path.basename(directionDir)
    timeDir = os.path.dirname(directionDir)
    timeBase = os.path.basename(timeDir)
    locDir = os.path.dirname(os.path.dirname(timeDir))
    locBase = os.path.basename(locDir)
    # print(vehicle, directionBase, timeBase,file_count)

    cond1 = (df.index == timeBase) & (df['Direction'] == 'Entry')
    cond2 = (df.index == timeBase) & (df['Direction'] == 'Exit')
    # try:
    #     pValue = int(df.loc[cond1]['heavytruck'].values[0])
    # except:
    #     pValue = 0
    total_count = file_count
    if(directionBase == 'Entry'):
        df.loc[cond1, vehicle] = str(total_count)
    elif(directionBase == 'Exit'):
        df.loc[cond2, vehicle] = str(total_count)
    # df.loc[df.index == timeBase, "Direction"] = directionBase



df.rename(columns={"undefined": "others", "car":"sedan"}, inplace= True)
df.replace(np.nan, 0, inplace=True)
df.set_index(['Time', 'Direction'], inplace=True)
# print(df)
saveFile = f'../Reports/{locBase}/{rootbase}.xlsx'
camWiseVideoReports = '../Reports'
saveFile = os.path.join(camWiseVideoReports, locBase, rootbase + '.xlsx')
# df.to_csv('logex.csv')
df.to_excel(saveFile)
del df