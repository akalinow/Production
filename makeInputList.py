#!/usr/bin/env python

import os, re
import commands
import math

inputDir= "/home/akalinow/scratch/CMS/HiggsCP/Data/WAWNTuples/2017/NTUPLES_11_09_2018/TT"
          
fileList = os.listdir(inputDir)

initString = "inputFiles = "

for aFile in fileList:
    if aFile.find("SUSY")!=-1:
        continue
    initString+=aFile+", "


print initString
