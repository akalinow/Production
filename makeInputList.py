#!/usr/bin/env python

import os, re
import commands
import math

inputDir= "/home/akalinow/scratch/CMS/HiggsCP/Data/WAWNTuples/2017/NTUPLES_05_12_2018/MT"
          
fileList = os.listdir(inputDir)

initString = "inputFiles = "

for aFile in fileList:
    if aFile.find("SUSY")!=-1:
        continue
    initString+=aFile+", "


print initString
