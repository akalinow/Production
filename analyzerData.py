#-----------------------------------------
#
#Producer controller
#
#-----------------------------------------
import os, re
PyFilePath = os.environ['CMSSW_BASE']+"/src/LLRHiggsTauTau/NtupleProducer/"

#samples list (it could be moved to a cfg file for better reading
#samples = [
#]
#apply corrections?
APPLYMUCORR=False
APPLYELECORR=True
#Cuts on the Objects (add more cuts with &&)
#MUCUT="(isGlobalMuon || (isTrackerMuon && numberOfMatches>0)) && abs(eta)<2.4 && pt>8"
#ELECUT="abs(eta)<2.5 && gsfTrack.trackerExpectedHitsInner.numberOfHits<=1 && pt>10"
#TAUCUT="pt>15"
#JETCUT="pt>15"

USEMVAMET=False
APPLYMETCORR=False # flag to enable (True) and disable (False) Z-recoil corrections
USE_NOHFMET = False # True to exclude HF and run on silver json

BUILDONLYOS=False #If true don't create the collection of SS candidates (and thus don't run SV fit on them)
APPLYTESCORRECTION=False # shift the central value of the tau energy scale before computing up/down variations

IsMC=False
Is25ns=True
HLTProcessName='HLT' #Different names possible, check e.g. at https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookMiniAOD.                                                               
if not IsMC:
    HLTProcessName='HLT' #It always 'HLT' for real data
print "HLTProcessName: ",HLTProcessName

#relaxed sets for testing purposes
TAUDISCRIMINATOR="byIsolationMVA3oldDMwoLTraw"
#PVERTEXCUT="!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2" #cut on good primary vertexes
PVERTEXCUT=""#No vertex selection in baseline selection HiggsToTauTauWorking2016#Vertices
MUCUT="isLooseMuon && pt>5"
ELECUT="pt>7"#"gsfTrack.hitPattern().numberOfHits(HitPattern::MISSING_INNER_HITS)<=1 && pt>10"
TAUCUT="(tauID('byCombinedIsolationDeltaBetaCorrRaw3Hits') < 1000.0 || tauID('byIsolationMVArun2v1DBoldDMwLTraw')>-0.999) && pt>18" #miniAOD tau from hpsPFTauProducer have pt>18 and decaymodefinding ID
JETCUT="pt>10"
LLCUT="mass>0"
BCUT="pt>5"

# ------------------------
DO_ENRICHED=False # do True by default, both ntuples and enriched outputs are saved!
STORE_ENRICHEMENT_ONLY=True # When True and DO_ENRICHED=True only collection additional to MiniAOD standard are stored. They can be used to reproduce ntuples when used together with orygi\nal MiniAOD with two-file-solution    
# ------------------------

is80X = True if 'CMSSW_8' in os.environ['CMSSW_VERSION'] else False# True to run in 80X (2016), False to run in 76X (2015)
print "is80X: " , is80X
is92X = True if 'CMSSW_9_2' in os.environ['CMSSW_VERSION'] else False# True to run in 92Y (2017), False to run in 76X (2015) or 80X (2016)
print "is92X: " , is92X
is94X = True if 'CMSSW_9_4' in os.environ['CMSSW_VERSION'] else False# True to run in 9XY (2017), False to run in 76X (2015) or 80X (2016)
print "is94X: " , is94X
##
## Standard sequence
##

RUN_PERIOD = "Run2017"

if is80X:
    execfile(PyFilePath+"python/HiggsTauTauProducer_80X.py")
elif is92X:
    execfile(PyFilePath+"python/HiggsTauTauProducer_92X.py")
elif is94X:
    execfile(PyFilePath+"python/HiggsTauTauProducer_94X.py")    
else :
    execfile(PyFilePath+"python/HiggsTauTauProducer.py")

### ----------------------------------------------------------------------
### Source, better to use sample to run on batch
### ----------------------------------------------------------------------
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/home/akalinow/scratch/CMS/HiggsCP/Data/SingleMuon/Run2017F-31Mar2018-v1/MINIAOD/00245C8B-8C37-E811-B942-002590E2F9D4.root'
        #'file:/mnt/home/mbluj/work/data/92X/MINIAOD/Run2017C_SingleMuon_PromptReco-v1/000_299_368_00000_5E4BC918-8C6D-E711-9C2F-02163E012A9F.root',
    )
)

#Limited nEv for testing purposes. -1 to run all events
process.maxEvents.input = 1000
#process.source.eventsToProcess = cms.untracked.VEventRange('256677:277938287-256677:max')

# JSON mask for data --> defined in the lumiMask file
# from JSON file
#if not IsMC:
#  execfile(PyFilePath+"python/lumiMask.py")
#  process.source.lumisToProcess = LUMIMASK

##
## Output file
##

process.TFileService=cms.Service('TFileService',fileName=cms.string('HTauTauAnalysis.root'))

if DO_ENRICHED:
    process.out = cms.OutputModule("PoolOutputModule",
        fileName = cms.untracked.string('Enriched_miniAOD.root'),
        outputCommands = cms.untracked.vstring('keep *'),
        fastCloning     = cms.untracked.bool(False),
        #Compression settings from MiniAOD allowing to save about 10% of disc space compared to defults ->                                                                                  
        compressionAlgorithm = cms.untracked.string('LZMA'),
        compressionLevel = cms.untracked.int32(4),
        dropMetaData = cms.untracked.string('ALL'),
        eventAutoFlushCompressedSize = cms.untracked.int32(15728640),
        overrideInputFileSplitLevels = cms.untracked.bool(True)
        # <-                                                                                                                                                                                
    )
    if STORE_ENRICHEMENT_ONLY:
        # Store only additional collections compared to MiniAOD necessary to reproduce ntuples (basically MVAMET, lepton pairs with SVFit and corrected jets)                               
        # Size of about 10% of full EnrichedMiniAOD                                                                                                                                         
        process.out.outputCommands.append('drop *')
        process.out.outputCommands.append('keep *_SVllCand_*_*')
        process.out.outputCommands.append('keep *_SVbypass_*_*')
        process.out.outputCommands.append('keep *_barellCand_*_*')
        process.out.outputCommands.append('keep *_corrMVAMET_*_*')
        process.out.outputCommands.append('keep *_MVAMET_*_*')
        process.out.outputCommands.append('keep *_jets_*_*')
        process.out.outputCommands.append('keep *_patJetsReapplyJEC_*_*')
        process.out.outputCommands.append('keep *_softLeptons_*_*')
        process.out.outputCommands.append('keep *_genInfo_*_*')
        #process.out.fileName = 'EnrichementForMiniAOD.root' #FIXME: change name of output file?                                                                                            
    process.end = cms.EndPath(process.out)

#process.options = cms.PSet(skipEvent =  cms.untracked.vstring('ProductNotFound')),
#process.p = cms.EndPath(process.HTauTauTree)
process.p = cms.Path(process.Candidates)

# Silence output
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000
#process.MessageLogger.categories.append('onlyError')
#process.MessageLogger.cerr.onlyError=cms.untracked.PSet(threshold  = cms.untracked.string('ERROR'))
#process.MessageLogger.cerr.threshold='ERROR'
#process.MessageLogger = cms.Service("MessageLogger",
#	destinations = cms.untracked.vstring('log.txt')
#)
#process.MessageLogger.threshold = cms.untracked.string('ERROR')

#processDumpFile = open('process.dump' , 'w')
#print >> processDumpFile, process.dumpPython()

if process.source.fileNames[0].find("Run2016H")>-1:
    process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v16'  
    print "Switching GlobalTag to", process.GlobalTag.globaltag
elif process.source.fileNames[0].find("Run2017B")>-1:
    process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v4'  
    print "Switching GlobalTag to", process.GlobalTag.globaltag
elif process.source.fileNames[0].find("Run2017C")>-1:
    if process.source.fileNames[0].find("PromptReco-v1")>-1:
        process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v5'
    elif process.source.fileNames[0].find("PromptReco-v2")>-1:
        process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v7'
    else:
        process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v8'
    print "Switching GlobalTag to", process.GlobalTag.globaltag
elif process.source.fileNames[0].find("Run2017D")>-1:
    process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v8'  
    print "Switching GlobalTag to", process.GlobalTag.globaltag
elif process.source.fileNames[0].find("Run2017E")>-1:
    process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v9'  
    print "Switching GlobalTag to", process.GlobalTag.globaltag
 
