#!/usr/bin/env python

import os
import os.path

from ROOT import gSystem, TChain, TSystem, TFile

doSvFit = True
if doSvFit :
    print "Run with SVFit computation"

#Checkout DNN training files of those are not present in the working area
#(dut to size the DNN training files should not be send with input sandbox)
DNN_data_path = os.environ["CMSSW_BASE"]+"/external/"+os.environ["SCRAM_ARCH"]+"/data/RecoTauTag/TrainingFiles/data"
isDNN_present = os.path.exists(DNN_data_path)

if not isDNN_present:
    command = "cd $CMSSW_BASE/src; "
    command += "git clone https://github.com/cms-tau-pog/RecoTauTag-TrainingFiles -b master RecoTauTag/TrainingFiles/data; "
    command += "cd -;"
    os.system(command)

#Some system have problem runnig compilation (missing glibc-static library?).
#First we try to compile, and only then we start time consuming cmssw
status = gSystem.CompileMacro('HTTEvent.cxx')
gSystem.Load('$CMSSW_BASE/lib/$SCRAM_ARCH/libTauAnalysisClassicSVfit.so')
status *= gSystem.CompileMacro('HTauTauTreeBase.C')
status *= gSystem.CompileMacro('HTauMuTauHTree.C')
status *= gSystem.CompileMacro('HTauhTauhTree.C')
status *= gSystem.CompileMacro('HMuMuTree.C')

print "Compilation status: ",status
if status==0:
    exit(-1)

#Produce framework report required by CRAB
command = "cmsRun -j FrameworkJobReport.xml -p PSet.py"
os.system(command)

from ROOT import HTauMuTauHTree
from ROOT import HTauhTauhTree
from ROOT import HMuMuTree

fileNames = []
#aFile = "file://./HTauTauAnalysis_GluGluHToTauTauM125.root"
#aFile = "file://./HTauTauAnalysis_DYJetsToLLM50.root"
aFile = "file://./HTauTauAnalysis.root"
fileNames.append(aFile)
print "Adding file: ",aFile
###
print "Making the mu*tau tree doSvFit = ",doSvFit
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
print "TTree entries: ",aTree.GetEntries()
HTauMuTauHTree(aTree,doSvFit).Loop()
###
print "Making the tau*tau tree doSvFit = ",doSvFit
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
print "TTree entries: ",aTree.GetEntries()
HTauhTauhTree(aTree,doSvFit).Loop()
print "Making the mu*mu tree doSvFit = ",doSvFit
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
print "TTree entries: ",aTree.GetEntries()
HMuMuTree(aTree, doSvFit).Loop()
###

