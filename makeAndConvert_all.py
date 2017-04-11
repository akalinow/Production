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
gSystem.CompileMacro('ScaleFactor.cc')
gSystem.Load('$CMSSW_BASE/lib/slc6_amd64_gcc530/libTauAnalysisSVfitStandalone.so')
gSystem.CompileMacro('HTauTauTreeBase.C')
gSystem.CompileMacro('HTauhTauhTree.C')
gSystem.CompileMacro('HTauTauTree.C')
gSystem.CompileMacro('HMuMuTree.C')
from ROOT import HTauhTauhTree
from ROOT import HTauTauTree
from ROOT import HMuMuTree

fileNames = [
#'/store/user/akalinow/HTauTauAnalysis_TAUCUT_fix.root'
'/export/cms/akalinow/CMS/HiggsCP/Prod/Crab/Production/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM/HTauTauAnalysis_2.root'
]
#aTree = TChain("HTauTauTree/HTauTauTree")
#for aFile in process.source.fileNames:
for aFile in fileNames:
    aFile = aFile.replace("Enriched_miniAOD","HTauTauAnalysis")
    #aFile = aFile.replace("/store","root://cms-xrd-global.cern.ch///store")
    aFile = aFile.replace("/store","root://se.cis.gov.pl:1094///store")
    print "Adding file: ",aFile
    #fileNames.append(aFile)
    #aTree.Add(aFile)
    aROOTFile = TFile.Open(aFile)
    aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
    print "TTree entries: ",aTree.GetEntries()
    print "Process MT..."
    HTauTauTree(aTree,doSvFit).Loop()
    print "done"
    # file and tree have to be opened again as they are closed by Dtor of analyzer
    aROOTFile = TFile.Open(aFile)
    aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
    print "TTree entries: ",aTree.GetEntries()
    print "Process TT..."
    HTauhTauhTree(aTree,doSvFit).Loop()
    print "done"
    # file and tree have to be opened again as they are closed by Dtor of analyzer
    aROOTFile = TFile.Open(aFile)
    aTree = aROOTFile.Get("HTauTauTree/HTauTauTree")
    print "TTree entries: ",aTree.GetEntries()
    print "Process MM..."
    HMuMuTree(aTree).Loop()
    print "done"

#print "TTree entries: ",aTree.GetEntries()
#HTauTauTree(aTree).Loop()

#Merge files.
#command = "hadd -f WAW_HTauTauAnalysis.root WAW_HTauTauAnalysis_*.root"
#os.system(command)

#print "Done!", "Processed ",len(process.source.fileNames), "files"
print "Done!", "Processed ",len(fileNames), "files"
