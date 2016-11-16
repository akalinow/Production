#!/usr/bin/env python                                                                                                                                                                       

import os, re
import commands
import math

inputDir="/scratch/cms/apyskir/Data/CP/NTUPLES_08_11_2016/"

fileList = os.listdir(inputDir)
        
inputDir = inputDir.replace("/scratch/", "/cms/")
initString = "inputFile = "

outfile = open('inputFileList.txt','w')

#MT
for aFile in fileList:
    if aFile.find("MM_")!=-1 or aFile.find("TT_")!=-1: 
        continue
    initString+=inputDir+"/"+aFile+", "
outfile.write(initString.rstrip(", ")+"\n")
print initString
initString = "inputFile = "

#TT
for aFile in fileList:
    if aFile.find("TT_")==-1: 
        continue
    initString+=inputDir+"/"+aFile+", "
outfile.write(initString.rstrip(", ")+"\n")
print initString
initString = "inputFile = "

#MT
for aFile in fileList:
    if aFile.find("MM_")==-1: 
        continue
    initString+=inputDir+"/"+aFile+", "
outfile.write(initString.rstrip(", ")+"\n")
print initString

outfile.close()
