/**
 * \file ToyRecoFunc.h
 *
 * \ingroup ToyReco
 * 
 * \brief Utility functions
 *
 * @author kazuhiro
 */

/** \addtogroup ToyReco

    @{*/
#ifndef TOYRECOFUNC_H
#define TOYRECOFUNC_H

#include <iostream>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include "ToyPulseReco.h"

/// Function to reconstruct pulses from an wavform & fill analysis histogram
TH1D* AnaTree(std::string file_name);

/// Function to reconstruct pulses from an wavform & store the output to TTree
void RecoTree(std::string file_name);

#endif
/** @} */ // end of doxygen group 

