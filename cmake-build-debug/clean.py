import os
import shutil

rootdir = '/data/scratch/henni-mohammed/data3/programs'

for dir in os.listdir(rootdir):
    array = dir.split('n')
    if int(array[2]) < 400:
        shutil.rmtree(os.path.join(rootdir, dir))
       # for e in array:
        #    print(e)
