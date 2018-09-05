#!/usr/bin/env python

import os, re
import commands
import math

inputDir= "/home/akalinow/scratch/CMS/HiggsCP/Data/WAWNTuples/2017/fullRun2017_v1/MT"
          
fileList = os.listdir(inputDir)

initString = "inputFiles = "

for aFile in fileList:
    if aFile.find("SUSY")!=-1:
        continue
    initString+=aFile+", "


print initString
