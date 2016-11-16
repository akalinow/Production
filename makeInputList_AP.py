#!/usr/bin/env python                                                                                                                                                                       

import os, re
import commands
import math

inputDir="/scratch/cms/apyskir/Data/CP/NTUPLES_08_11_2016/"

fileList = os.listdir(inputDir)
        
initString = "inputFile = "

#MT
for aFile in fileList:
    if aFile.find("MM_")!=-1 or aFile.find("TT_")!=-1: 
        continue
    initString+=inputDir+"/"+aFile+", "

#TT
for aFile in fileList:
    if aFile.find("TT_")==-1: 
        continue
    initString+=inputDir+"/"+aFile+", "

#MT
for aFile in fileList:
    if aFile.find("MM_")==-1: 
        continue
    initString+=inputDir+"/"+aFile+", "


print initString
