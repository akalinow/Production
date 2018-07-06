#ifndef HMuMuTree_h
#define HMuMuTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

#include "HTTEvent.h"
#include <iostream>

// Header of the base class
#include "HTauTauTreeBase.h"

class HMuMuTree : public HTauTauTreeBase {
 public :

  /////////////////////////////////////////////////
  /// MM final state specific
  bool pairSelection(unsigned int index);
  unsigned int bestPair(std::vector<unsigned int> &pairIndexes);
  /////////////////////////////////////////////////
  
  HMuMuTree(TTree *tree=0, bool doSvFit=false, std::string prefix="WAWMM");
  virtual ~HMuMuTree();
  
};

#endif

#ifdef HMuMuTree_cxx
HMuMuTree::HMuMuTree(TTree *tree, bool doSvFit, std::string prefix) : HTauTauTreeBase(tree, doSvFit, prefix) 
{}

HMuMuTree::~HMuMuTree()
{}

#endif // #ifdef HMuMuTree_cxx
