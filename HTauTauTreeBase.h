//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul 15 12:43:55 2016 by ROOT version 6.02/13
// from TTree HTauTauTree/HTauTauTree
// found on file: HTauTauAnalysis.root
//////////////////////////////////////////////////////////

#ifndef HTauTauTreeBase_h
#define HTauTauTreeBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TMatrixD.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

#include "AnalysisEnums.h"
#include "HTTEvent.h"
#include <iostream>

#include "TauAnalysis/ClassicSVfit/interface/ClassicSVfit.h"
#include "TauAnalysis/ClassicSVfit/interface/MeasuredTauLepton.h"

class HTauTauTreeBase {
public :

/////////////////////////////////////////////////
  virtual void initWawTree(TTree *tree, std::string prefix="WAW");

  void fillEvent();
  virtual void fillPairs(unsigned int bestPairIndex);
  virtual void fillJets(unsigned int bestPairIndex);
  virtual void fillLeptons();
  virtual void fillGenLeptons();
  virtual bool thirdLeptonVeto(unsigned int signalLeg1Index, unsigned int signalLeg2Index, int leptonPdg, double dRmin=-1);
  virtual bool extraMuonVeto(unsigned int signalLeg1Index, unsigned int signalLeg2Index, double dRmin=-1);
  virtual bool extraElectronVeto(unsigned int signalLeg1Index, unsigned int signalLeg2Index, double dRmin=-1);
  bool muonSelection(unsigned int index);
  bool electronSelection(unsigned int index);
  virtual bool pairSelection(unsigned int index);
  virtual unsigned int bestPair(std::vector<unsigned int> &pairIndexes);
  void computeSvFit(HTTPair &aPair, HTTAnalysis::sysEffects type=HTTAnalysis::NOMINAL);
  TLorentzVector runSVFitAlgo(const std::vector<classic_svFit::MeasuredTauLepton> & measuredTauLeptons,
			      const TVector2 &aMET, const TMatrixD &covMET);
  bool jetSelection(unsigned int index, unsigned int bestPairIndex);
  int getMCMatching(unsigned int index);
  double getPtReweight(bool doSUSY=false);
  bool isGoodToMatch(unsigned int ind);
  TLorentzVector getGenComponentP4(unsigned int index, unsigned int iAbsCharge);

  template<typename T> T getBranchValue(char *branchAddress, unsigned int index);
  Double_t getProperty(std::string name, unsigned int index);
  std::vector<Double_t> getProperties(const std::vector<std::string> & propertiesList, unsigned int index);
  void writePropertiesHeader(const std::vector<std::string> & propertiesList);
  void writeTriggersHeader(const TH1F*);

  void fillSVFitTree(const std::vector<classic_svFit::MeasuredTauLepton> & measuredTauLeptons,
		     const TVector2 &aMET, const TMatrixD &covMET, float mcMass, float cubaMass,
		     float cpuTimeMC, float cpuTimeCuba);

  SVFitEvent *aSVFitEvent;
  TTree *svFitTree;
  
  std::vector<HTTPair> httPairCollection;
  std::vector<HTTParticle> httJetCollection;
  std::vector<HTTParticle> httLeptonCollection;
  std::vector<HTTParticle> httGenLeptonCollection;
  TTree *warsawTree;
  TFile *warsawFile;
  HTTEvent *httEvent;
  TH1F* hStats;
  TH2F* zptmass_histo, *zptmass_histo_SUSY;
  
  unsigned int bestPairIndex_;

  bool doSvFit_;
  ClassicSVfit svFitAlgo;
  
  TFile* zPtReweightFile, *zPtReweightSUSYFile;
  TLorentzVector p4SVFit, p4Leg1SVFit, p4Leg2SVFit;   

  std::vector<std::string> leptonPropertiesList, genLeptonPropertiesList;

   /////////////////////////////////////////////////
  
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
     ULong64_t       EventNumber;
   Int_t           RunNumber;
   Int_t           lumi;
   Long64_t        triggerbit;
   Int_t           metfilterbit;
   Double_t        met;
   Double_t        metphi;
   Double_t        PUPPImet;
   Double_t        PUPPImetphi;
   Double_t        PFMETCov00;
   Double_t        PFMETCov01;
   Double_t        PFMETCov10;
   Double_t        PFMETCov11;
   Double_t        PFMETsignif;
   Int_t           npv;
   Double_t        npu;
   Double_t        PUReweight;
   Double_t        rho;
   vector<double>  *mothers_px;
   vector<double>  *mothers_py;
   vector<double>  *mothers_pz;
   vector<double>  *mothers_e;
   vector<double>  *daughters_px;
   vector<double>  *daughters_py;
   vector<double>  *daughters_pz;
   vector<double>  *daughters_e;
   vector<int>     *daughters_charge;
   vector<double>  *daughters_charged_px;
   vector<double>  *daughters_charged_py;
   vector<double>  *daughters_charged_pz;
   vector<double>  *daughters_charged_e;
   vector<double>  *daughters_neutral_px;
   vector<double>  *daughters_neutral_py;
   vector<double>  *daughters_neutral_pz;
   vector<double>  *daughters_neutral_e;
   vector<int>     *daughters_TauUpExists;
   vector<double>  *daughters_px_TauUp;
   vector<double>  *daughters_py_TauUp;
   vector<double>  *daughters_pz_TauUp;
   vector<double>  *daughters_e_TauUp;
   vector<int>     *daughters_TauDownExists;
   vector<double>  *daughters_px_TauDown;
   vector<double>  *daughters_py_TauDown;
   vector<double>  *daughters_pz_TauDown;
   vector<double>  *daughters_e_TauDown;
   Int_t           PUNumInteractions;
   vector<int>     *daughters_genindex;
   Double_t        MC_weight;
   Double_t        MC_weight_scale_muF0p5;
   Double_t        MC_weight_scale_muF2;
   Double_t        MC_weight_scale_muR0p5;
   Double_t        MC_weight_scale_muR2;
   Double_t        lheHt;
   Int_t           lheNOutPartons;
   Int_t           lheNOutB;
   Double_t        aMCatNLOweight;
   vector<double>  *genpart_px;
   vector<double>  *genpart_py;
   vector<double>  *genpart_pz;
   vector<double>  *genpart_e;
   vector<double>  *genpart_pca_x;
   vector<double>  *genpart_pca_y;
   vector<double>  *genpart_pca_z;
   vector<double>  *genpart_sv_x;
   vector<double>  *genpart_sv_y;
   vector<double>  *genpart_sv_z;
   vector<int>     *genpart_pdg;
   vector<int>     *genpart_status;
   vector<int>     *genpart_HMothInd;
   vector<int>     *genpart_MSSMHMothInd;
   vector<int>     *genpart_TopMothInd;
   vector<int>     *genpart_TauMothInd;
   vector<int>     *genpart_ZMothInd;
   vector<int>     *genpart_WMothInd;
   vector<int>     *genpart_bMothInd;
   vector<int>     *genpart_HZDecayMode;
   vector<int>     *genpart_TopDecayMode;
   vector<int>     *genpart_WDecayMode;
   vector<int>     *genpart_TauGenDecayMode;
   vector<int>     *genpart_TauGenDetailedDecayMode;
   vector<int>     *genpart_flags;
   vector<double>  *genjet_px;
   vector<double>  *genjet_py;
   vector<double>  *genjet_pz;
   vector<double>  *genjet_e;
   vector<int>     *genjet_partonFlavour;
   vector<int>     *genjet_hadronFlavour;
   Int_t           NUP;
   vector<bool>    *isOSCand;
   vector<double>  *METx;
   vector<double>  *METy;
   vector<double>  *uncorrMETx;
   vector<double>  *uncorrMETy;
   vector<double>  *MET_cov00;
   vector<double>  *MET_cov01;
   vector<double>  *MET_cov10;
   vector<double>  *MET_cov11;
   vector<double>  *MET_significance;
   vector<double>  *mT_Dau1;
   vector<double>  *mT_Dau2;
   vector<int>     *PDGIdDaughters;
   vector<int>     *indexDau1;
   vector<int>     *indexDau2;
   vector<int>     *particleType;
   vector<double>  *discriminator;
   vector<int>     *daughters_muonID;
   vector<int>     *daughters_typeOfMuon;
   vector<double>  *dxy;
   vector<double>  *dz;
   vector<double>  *dxy_innerTrack;
   vector<double>  *dz_innerTrack;
   vector<double>  *daughters_rel_error_trackpt;
   vector<double>  *SIP;
   vector<bool>    *daughters_iseleBDT;
   vector<bool>    *daughters_iseleWP80;
   vector<bool>    *daughters_iseleWP90;
   vector<double>  *daughters_eleMVAnt;
   vector<bool>    *daughters_passConversionVeto;
   vector<int>     *daughters_eleMissingHits;
   vector<bool>    *daughters_iseleChargeConsistent;
   vector<int>     *daughters_eleCUTID;
   vector<int>     *decayMode;
   vector<Long64_t> *tauID;
   vector<double>  *combreliso;
   vector<double>  *combreliso03;
   vector<double>  *daughters_IetaIeta;
   vector<double>  *daughters_hOverE;
   vector<double>  *daughters_deltaEtaSuperClusterTrackAtVtx;
   vector<double>  *daughters_deltaPhiSuperClusterTrackAtVtx;
   vector<double>  *daughters_IoEmIoP;
   vector<double>  *daughters_IoEmIoP_ttH;
   vector<double>  *daughters_SCeta;
   vector<double>  *daughters_depositR03_tracker;
   vector<double>  *daughters_depositR03_ecal;
   vector<double>  *daughters_depositR03_hcal;
   vector<int>     *daughters_decayModeFindingOldDMs;
   vector<double>  *againstElectronMVA5category;
   vector<double>  *againstElectronMVA5raw;
   vector<double>  *photonPtSumOutsideSignalCone;
   vector<int>     *daughters_decayModeFindingNewDMs;
   vector<double>  *daughters_byCombinedIsolationDeltaBetaCorrRaw3Hits;
   vector<double>  *daughters_byIsolationMVArun2v1DBoldDMwLTraw;
   vector<double>  *daughters_byIsolationMVArun2v1DBoldDMwLTraw2017v2;
   vector<double>  *daughters_byIsolationMVArun2v1DBnewDMwLTraw2017v2;
   vector<double>  *daughters_deepTau2017v1tauVSe;
   vector<double>  *daughters_deepTau2017v1tauVSmu;
   vector<double>  *daughters_deepTau2017v1tauVSjet;
   vector<double>  *daughters_deepTau2017v1tauVSall;
   vector<double>  *daughters_DPFTau_2016_v0tauVSall;
   vector<double>  *daughters_DPFTau_2016_v1tauVSall;
   vector<double>  *daughters_chargedIsoPtSum;
   vector<double>  *daughters_neutralIsoPtSum;
   vector<double>  *daughters_chargedIsoPtSumdR03;
   vector<double>  *daughters_neutralIsoPtSumdR03;
   vector<double>  *daughters_puCorrPtSum;
   vector<int>     *daughters_numChargedParticlesSignalCone;
   vector<int>     *daughters_numNeutralHadronsSignalCone;
   vector<int>     *daughters_numPhotonsSignalCone;
   vector<int>     *daughters_daughters_numParticlesSignalCone;
   vector<int>     *daughters_numChargedParticlesIsoCone;
   vector<int>     *daughters_numNeutralHadronsIsoCone;
   vector<int>     *daughters_numPhotonsIsoCone;
   vector<int>     *daughters_numParticlesIsoCone;
   vector<double>  *daughters_leadChargedParticlePt;
   vector<double>  *daughters_trackRefPt;
   vector<int>     *daughters_nPhoton;
   vector<double>  *daughters_ptWeightedDetaStrip;
   vector<double>  *daughters_ptWeightedDphiStrip;
   vector<double>  *daughters_ptWeightedDrSignal;
   vector<double>  *daughters_ptWeightedDrIsolation;
   vector<double>  *daughters_eRatio;
   vector<double>  *daughters_dxy_Sig;
   vector<double>  *daughters_ip3d;
   vector<double>  *daughters_ip3d_Sig;
   vector<int>     *daughters_hasSecondaryVertex;
   vector<double>  *daughters_decayDistMag;
   vector<double>  *daughters_flightLengthSig;
   vector<double>  *daughters_gjAngleDiff;
   vector<int>     *daughters_isLastTriggerObjectforPath;
   vector<Long64_t> *daughters_trgMatched;
   vector<int>     *daughters_isTriggerObjectforPath;
   vector<Long64_t> *daughters_FilterFired;
   vector<Long64_t> *daughters_isGoodTriggerType;
   vector<Long64_t> *daughters_L3FilterFired;
   vector<Long64_t> *daughters_L3FilterFiredLast;
   vector<double>  *daughters_HLTpt;
   vector<bool>    *daughters_isL1IsoTau28Matched;
   vector<int>     *daughters_jetNDauChargedMVASel;
   vector<double>  *daughters_miniRelIsoCharged;
   vector<double>  *daughters_miniRelIsoNeutral;
   vector<double>  *daughters_jetPtRel;
   vector<double>  *daughters_jetPtRatio;
   vector<double>  *daughters_jetBTagCSV;
   vector<double>  *daughters_lepMVA_mvaId;
   vector<double>  *daughters_pca_x;
   vector<double>  *daughters_pca_y;
   vector<double>  *daughters_pca_z;
   vector<double>  *daughters_pcaRefitPV_x;
   vector<double>  *daughters_pcaRefitPV_y;
   vector<double>  *daughters_pcaRefitPV_z;
   vector<double>  *daughters_pcaGenPV_x;
   vector<double>  *daughters_pcaGenPV_y;
   vector<double>  *daughters_pcaGenPV_z;
   vector<double>  *daughters_sv_x;
   vector<double>  *daughters_sv_y;
   vector<double>  *daughters_sv_z;
   Int_t           JetsNumber;
   vector<double>  *jets_px;
   vector<double>  *jets_py;
   vector<double>  *jets_pz;
   vector<double>  *jets_e;
   vector<double>  *jets_rawPt;
   vector<double>  *jets_area;
   vector<double>  *jets_mT;
   vector<int>     *jets_Flavour;
   vector<int>     *jets_HadronFlavour;
   vector<int>     *jets_genjetIndex;
   vector<double>  *jets_PUJetID;
   vector<double>  *jets_PUJetIDupdated;
   vector<double>  *jets_vtxPt;
   vector<double>  *jets_vtxMass;
   vector<double>  *jets_vtx3dL;
   vector<double>  *jets_vtxNtrk;
   vector<double>  *jets_vtx3deL;
   vector<double>  *jets_leadTrackPt;
   vector<double>  *jets_leptonPtRel;
   vector<double>  *jets_leptonPt;
   vector<double>  *jets_leptonDeltaR;
   vector<double>  *jets_chEmEF;
   vector<double>  *jets_chHEF;
   vector<double>  *jets_nEmEF;
   vector<double>  *jets_nHEF;
   vector<int>     *jets_chMult;
   vector<double>  *jets_jecUnc;
   vector<double>  *bDiscriminator;
   vector<double>  *bCSVscore;
   vector<double>  *pfCombinedMVAV2BJetTags;
   vector<int>     *PFjetID;
   vector<double>  *jetRawf;
   vector<double>  *ak8jets_px;
   vector<double>  *ak8jets_py;
   vector<double>  *ak8jets_pz;
   vector<double>  *ak8jets_e;
   vector<double>  *ak8jets_SoftDropMass;
   vector<double>  *ak8jets_PrunedMass;
   vector<double>  *ak8jets_TrimmedMass;
   vector<double>  *ak8jets_FilteredMass;
   vector<double>  *ak8jets_tau1;
   vector<double>  *ak8jets_tau2;
   vector<double>  *ak8jets_tau3;
   vector<double>  *ak8jets_CSV;
   vector<int>     *ak8jets_nsubjets;
   vector<double>  *subjets_px;
   vector<double>  *subjets_py;
   vector<double>  *subjets_pz;
   vector<double>  *subjets_e;
   vector<double>  *subjets_CSV;
   vector<int>     *subjets_ak8MotherIdx;
   Double_t        pv_x;
   Double_t        pv_y;
   Double_t        pv_z;
   Double_t        pvRefit_x;
   Double_t        pvRefit_y;
   Double_t        pvRefit_z;
   Double_t        pvGen_x;
   Double_t        pvGen_y;
   Double_t        pvGen_z;
   Bool_t          isRefitPV;

   // List of branches
   TBranch        *b_EventNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_triggerbit;   //!
   TBranch        *b_metfilterbit;   //!
   TBranch        *b_met;   //!
   TBranch        *b_metphi;   //!
   TBranch        *b_PUPPImet;   //!
   TBranch        *b_PUPPImetphi;   //!
   TBranch        *b_PFMETCov00;   //!
   TBranch        *b_PFMETCov01;   //!
   TBranch        *b_PFMETCov10;   //!
   TBranch        *b_PFMETCov11;   //!
   TBranch        *b_PFMETsignif;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_PUReweight;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_mothers_px;   //!
   TBranch        *b_mothers_py;   //!
   TBranch        *b_mothers_pz;   //!
   TBranch        *b_mothers_e;   //!
   TBranch        *b_daughters_px;   //!
   TBranch        *b_daughters_py;   //!
   TBranch        *b_daughters_pz;   //!
   TBranch        *b_daughters_e;   //!
   TBranch        *b_daughters_charge;   //!
   TBranch        *b_daughters_charged_px;   //!
   TBranch        *b_daughters_charged_py;   //!
   TBranch        *b_daughters_charged_pz;   //!
   TBranch        *b_daughters_charged_e;   //!
   TBranch        *b_daughters_neutral_px;   //!
   TBranch        *b_daughters_neutral_py;   //!
   TBranch        *b_daughters_neutral_pz;   //!
   TBranch        *b_daughters_neutral_e;   //!
   TBranch        *b_daughters_TauUpExists;   //!
   TBranch        *b_daughters_px_TauUp;   //!
   TBranch        *b_daughters_py_TauUp;   //!
   TBranch        *b_daughters_pz_TauUp;   //!
   TBranch        *b_daughters_e_TauUp;   //!
   TBranch        *b_daughters_TauDownExists;   //!
   TBranch        *b_daughters_px_TauDown;   //!
   TBranch        *b_daughters_py_TauDown;   //!
   TBranch        *b_daughters_pz_TauDown;   //!
   TBranch        *b_daughters_e_TauDown;   //!
   TBranch        *b_PUNumInteractions;   //!
   TBranch        *b_daughters_genindex;   //!
   TBranch        *b_MC_weight;   //!
   TBranch        *b_MC_weight_scale_muF0p5;   //!
   TBranch        *b_MC_weight_scale_muF2;   //!
   TBranch        *b_MC_weight_scale_muR0p5;   //!
   TBranch        *b_MC_weight_scale_muR2;   //!
   TBranch        *b_lheHt;   //!
   TBranch        *b_lheNOutPartons;   //!
   TBranch        *b_lheNOutB;   //!
   TBranch        *b_aMCatNLOweight;   //!
   TBranch        *b_genpart_px;   //!
   TBranch        *b_genpart_py;   //!
   TBranch        *b_genpart_pz;   //!
   TBranch        *b_genpart_e;   //!
   TBranch        *b_genpart_pca_x;   //!
   TBranch        *b_genpart_pca_y;   //!
   TBranch        *b_genpart_pca_z;   //!
   TBranch        *b_genpart_sv_x;   //!
   TBranch        *b_genpart_sv_y;   //!
   TBranch        *b_genpart_sv_z;   //!
   TBranch        *b_genpart_pdg;   //!
   TBranch        *b_genpart_status;   //!
   TBranch        *b_genpart_HMothInd;   //!
   TBranch        *b_genpart_MSSMHMothInd;   //!
   TBranch        *b_genpart_TopMothInd;   //!
   TBranch        *b_genpart_TauMothInd;   //!
   TBranch        *b_genpart_ZMothInd;   //!
   TBranch        *b_genpart_WMothInd;   //!
   TBranch        *b_genpart_bMothInd;   //!
   TBranch        *b_genpart_HZDecayMode;   //!
   TBranch        *b_genpart_TopDecayMode;   //!
   TBranch        *b_genpart_WDecayMode;   //!
   TBranch        *b_genpart_TauGenDecayMode;   //!
   TBranch        *b_genpart_TauGenDetailedDecayMode;   //!
   TBranch        *b_genpart_flags;   //!
   TBranch        *b_genjet_px;   //!
   TBranch        *b_genjet_py;   //!
   TBranch        *b_genjet_pz;   //!
   TBranch        *b_genjet_e;   //!
   TBranch        *b_genjet_partonFlavour;   //!
   TBranch        *b_genjet_hadronFlavour;   //!
   TBranch        *b_NUP;   //!
   TBranch        *b_isOSCand;   //!
   TBranch        *b_METx;   //!
   TBranch        *b_METy;   //!
   TBranch        *b_uncorrMETx;   //!
   TBranch        *b_uncorrMETy;   //!
   TBranch        *b_MET_cov00;   //!
   TBranch        *b_MET_cov01;   //!
   TBranch        *b_MET_cov10;   //!
   TBranch        *b_MET_cov11;   //!
   TBranch        *b_MET_significance;   //!
   TBranch        *b_mT_Dau1;   //!
   TBranch        *b_mT_Dau2;   //!
   TBranch        *b_PDGIdDaughters;   //!
   TBranch        *b_indexDau1;   //!
   TBranch        *b_indexDau2;   //!
   TBranch        *b_particleType;   //!
   TBranch        *b_discriminator;   //!
   TBranch        *b_daughters_muonID;   //!
   TBranch        *b_daughters_typeOfMuon;   //!
   TBranch        *b_dxy;   //!
   TBranch        *b_dz;   //!
   TBranch        *b_dxy_innerTrack;   //!
   TBranch        *b_dz_innerTrack;   //!
   TBranch        *b_daughters_rel_error_trackpt;   //!
   TBranch        *b_SIP;   //!
   TBranch        *b_daughters_iseleBDT;   //!
   TBranch        *b_daughters_iseleWP80;   //!
   TBranch        *b_daughters_iseleWP90;   //!
   TBranch        *b_daughters_eleMVAnt;   //!
   TBranch        *b_daughters_passConversionVeto;   //!
   TBranch        *b_daughters_eleMissingHits;   //!
   TBranch        *b_daughters_iseleChargeConsistent;   //!
   TBranch        *b_daughters_eleCUTID;   //!
   TBranch        *b_decayMode;   //!
   TBranch        *b_tauID;   //!
   TBranch        *b_combreliso;   //!
   TBranch        *b_combreliso03;   //!
   TBranch        *b_daughters_IetaIeta;   //!
   TBranch        *b_daughters_hOverE;   //!
   TBranch        *b_daughters_deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_daughters_deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_daughters_IoEmIoP;   //!
   TBranch        *b_daughters_IoEmIoP_ttH;   //!
   TBranch        *b_daughters_SCeta;   //!
   TBranch        *b_daughters_depositR03_tracker;   //!
   TBranch        *b_daughters_depositR03_ecal;   //!
   TBranch        *b_daughters_depositR03_hcal;   //!
   TBranch        *b_daughters_decayModeFindingOldDMs;   //!
   TBranch        *b_againstElectronMVA5category;   //!
   TBranch        *b_againstElectronMVA5raw;   //!
   TBranch        *b_photonPtSumOutsideSignalCone;   //!
   TBranch        *b_daughters_decayModeFindingNewDMs;   //!
   TBranch        *b_daughters_byCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_daughters_byIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_daughters_byIsolationMVArun2v1DBoldDMwLTraw2017v2;   //!
   TBranch        *b_daughters_byIsolationMVArun2v1DBnewDMwLTraw2017v2;   //!
   TBranch        *b_daughters_deepTau2017v1tauVSe;   //!
   TBranch        *b_daughters_deepTau2017v1tauVSmu;   //!
   TBranch        *b_daughters_deepTau2017v1tauVSjet;   //!
   TBranch        *b_daughters_deepTau2017v1tauVSall;   //!
   TBranch        *b_daughters_DPFTau_2016_v0tauVSall;   //!
   TBranch        *b_daughters_DPFTau_2016_v1tauVSall;   //!
   TBranch        *b_daughters_chargedIsoPtSum;   //!
   TBranch        *b_daughters_neutralIsoPtSum;   //!
   TBranch        *b_daughters_chargedIsoPtSumdR03;   //!
   TBranch        *b_daughters_neutralIsoPtSumdR03;   //!
   TBranch        *b_daughters_puCorrPtSum;   //!
   TBranch        *b_daughters_numChargedParticlesSignalCone;   //!
   TBranch        *b_daughters_numNeutralHadronsSignalCone;   //!
   TBranch        *b_daughters_numPhotonsSignalCone;   //!
   TBranch        *b_daughters_daughters_numParticlesSignalCone;   //!
   TBranch        *b_daughters_numChargedParticlesIsoCone;   //!
   TBranch        *b_daughters_numNeutralHadronsIsoCone;   //!
   TBranch        *b_daughters_numPhotonsIsoCone;   //!
   TBranch        *b_daughters_numParticlesIsoCone;   //!
   TBranch        *b_daughters_leadChargedParticlePt;   //!
   TBranch        *b_daughters_trackRefPt;   //!
   TBranch        *b_daughters_nPhoton;   //!
   TBranch        *b_daughters_ptWeightedDetaStrip;   //!
   TBranch        *b_daughters_ptWeightedDphiStrip;   //!
   TBranch        *b_daughters_ptWeightedDrSignal;   //!
   TBranch        *b_daughters_ptWeightedDrIsolation;   //!
   TBranch        *b_daughters_eRatio;   //!
   TBranch        *b_daughters_dxy_Sig;   //!
   TBranch        *b_daughters_ip3d;   //!
   TBranch        *b_daughters_ip3d_Sig;   //!
   TBranch        *b_daughters_hasSecondaryVertex;   //!
   TBranch        *b_daughters_decayDistMag;   //!
   TBranch        *b_daughters_flightLengthSig;   //!
   TBranch        *b_daughters_gjAngleDiff;   //!
   TBranch        *b_daughters_isLastTriggerObjectforPath;   //!
   TBranch        *b_daughters_trgMatched;   //!
   TBranch        *b_daughters_isTriggerObjectforPath;   //!
   TBranch        *b_daughters_FilterFired;   //!
   TBranch        *b_daughters_isGoodTriggerType;   //!
   TBranch        *b_daughters_L3FilterFired;   //!
   TBranch        *b_daughters_L3FilterFiredLast;   //!
   TBranch        *b_daughters_HLTpt;   //!
   TBranch        *b_daughters_isL1IsoTau28Matched;   //!
   TBranch        *b_daughters_jetNDauChargedMVASel;   //!
   TBranch        *b_daughters_miniRelIsoCharged;   //!
   TBranch        *b_daughters_miniRelIsoNeutral;   //!
   TBranch        *b_daughters_jetPtRel;   //!
   TBranch        *b_daughters_jetPtRatio;   //!
   TBranch        *b_daughters_jetBTagCSV;   //!
   TBranch        *b_daughters_lepMVA_mvaId;   //!
   TBranch        *b_daughters_pca_x;   //!
   TBranch        *b_daughters_pca_y;   //!
   TBranch        *b_daughters_pca_z;   //!
   TBranch        *b_daughters_pcaRefitPV_x;   //!
   TBranch        *b_daughters_pcaRefitPV_y;   //!
   TBranch        *b_daughters_pcaRefitPV_z;   //!
   TBranch        *b_daughters_pcaGenPV_x;   //!
   TBranch        *b_daughters_pcaGenPV_y;   //!
   TBranch        *b_daughters_pcaGenPV_z;   //!
   TBranch        *b_daughters_sv_x;   //!
   TBranch        *b_daughters_sv_y;   //!
   TBranch        *b_daughters_sv_z;   //!
   TBranch        *b_JetsNumber;   //!
   TBranch        *b_jets_px;   //!
   TBranch        *b_jets_py;   //!
   TBranch        *b_jets_pz;   //!
   TBranch        *b_jets_e;   //!
   TBranch        *b_jets_rawPt;   //!
   TBranch        *b_jets_area;   //!
   TBranch        *b_jets_mT;   //!
   TBranch        *b_jets_Flavour;   //!
   TBranch        *b_jets_HadronFlavour;   //!
   TBranch        *b_jets_genjetIndex;   //!
   TBranch        *b_jets_PUJetID;   //!
   TBranch        *b_jets_PUJetIDupdated;   //!
   TBranch        *b_jets_vtxPt;   //!
   TBranch        *b_jets_vtxMass;   //!
   TBranch        *b_jets_vtx3dL;   //!
   TBranch        *b_jets_vtxNtrk;   //!
   TBranch        *b_jets_vtx3deL;   //!
   TBranch        *b_jets_leadTrackPt;   //!
   TBranch        *b_jets_leptonPtRel;   //!
   TBranch        *b_jets_leptonPt;   //!
   TBranch        *b_jets_leptonDeltaR;   //!
   TBranch        *b_jets_chEmEF;   //!
   TBranch        *b_jets_chHEF;   //!
   TBranch        *b_jets_nEmEF;   //!
   TBranch        *b_jets_nHEF;   //!
   TBranch        *b_jets_chMult;   //!
   TBranch        *b_jets_jecUnc;   //!
   TBranch        *b_bDiscriminator;   //!
   TBranch        *b_bCSVscore;   //!
   TBranch        *b_pfCombinedMVAV2BJetTags;   //!
   TBranch        *b_PFjetID;   //!
   TBranch        *b_jetRawf;   //!
   TBranch        *b_ak8jets_px;   //!
   TBranch        *b_ak8jets_py;   //!
   TBranch        *b_ak8jets_pz;   //!
   TBranch        *b_ak8jets_e;   //!
   TBranch        *b_ak8jets_SoftDropMass;   //!
   TBranch        *b_ak8jets_PrunedMass;   //!
   TBranch        *b_ak8jets_TrimmedMass;   //!
   TBranch        *b_ak8jets_FilteredMass;   //!
   TBranch        *b_ak8jets_tau1;   //!
   TBranch        *b_ak8jets_tau2;   //!
   TBranch        *b_ak8jets_tau3;   //!
   TBranch        *b_ak8jets_CSV;   //!
   TBranch        *b_ak8jets_nsubjets;   //!
   TBranch        *b_subjets_px;   //!
   TBranch        *b_subjets_py;   //!
   TBranch        *b_subjets_pz;   //!
   TBranch        *b_subjets_e;   //!
   TBranch        *b_subjets_CSV;   //!
   TBranch        *b_subjets_ak8MotherIdx;   //!
   TBranch        *b_pv_x;   //!
   TBranch        *b_pv_y;   //!
   TBranch        *b_pv_z;   //!
   TBranch        *b_pvRefit_x;   //!
   TBranch        *b_pvRefit_y;   //!
   TBranch        *b_pvRefit_z;   //!
   TBranch        *b_pvGen_x;   //!
   TBranch        *b_pvGen_y;   //!
   TBranch        *b_pvGen_z;   //!
   TBranch        *b_isRefitPV;   //!
 

   HTauTauTreeBase(TTree *tree=0, bool doSvFit=false, std::string prefix="WAW");
   virtual ~HTauTauTreeBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif
