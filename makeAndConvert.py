#!/usr/bin/env python

import os

from ROOT import gSystem, TChain, TSystem, TFile
from PSet import process

doSvFit = True
if doSvFit :
    print "Run with SVFit computation"

#Produce framework report required by CRAB
command = "cmsRun -j FrameworkJobReport.xml -p PSet.py"
os.system(command)

gSystem.CompileMacro('HTTEvent.cxx')
gSystem.Load('$CMSSW_BASE/lib/slc6_amd64_gcc530/libTauAnalysisSVfitStandalone.so')
gSystem.CompileMacro('HTauTauTreeBase.C')
gSystem.CompileMacro('HTauTauTree.C')
gSystem.CompileMacro('HTauhTauhTree.C')
gSystem.CompileMacro('HMuMuTree.C')
from ROOT import HTauTauTree
from ROOT import HTauhTauhTree
from ROOT import HMuMuTree

fileNames = []
aFile = "file:///scratch/cms/akalinow/CMS/HiggsCP/Prod/Crab/Production/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM/HTauTauAnalysis_PFMETcorr_USEPAIRMETfix.root"
fileNames.append(aFile)

print "Adding file: ",aFile

print "Making the mu*tau tree"
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
print "TTree entries: ",aTree.GetEntries()
HTauTauTree(aTree,doSvFit).Loop()

print "Making the tau*tau tree"
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
HTauhTauhTree(aTree,doSvFit).Loop()

print "Making the mu*mu tree"
aROOTFile = TFile.Open(aFile)
aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
HMuMuTree(aTree).Loop()
