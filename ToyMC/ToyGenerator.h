/**
 * \file ToyGenerator.h
 *
 * \ingroup ToyMC
 * 
 * \brief Class def header for a class ToyGenerator
 *
 * @author kazuhiro
 */

/** \addtogroup ToyMC

    @{*/
#ifndef TOYGENERATOR_H
#define TOYGENERATOR_H

#include <iostream>
#include <TF1.h>
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
/**
   \class ToyGenerator
   @brief An example C++ class to generate a toy waveform
   Can generate either gaussian or poisson shaped waveform.
 */
class ToyGenerator{

public:

  /// Default constructor
  ToyGenerator();

  /// Default destructor
  virtual ~ToyGenerator(){}

  /// Gaussian shape parameter setter
  void SetParamsGaus(double amp, double mean, double width)
  { fGaus.SetParameters(amp,mean,width); }

  /// Landau shape parameter setter
  void SetParamsLandau(double amp, double mean, double width);

  /// Gaussian waveform generator
  std::vector<short> Gaussian(size_t wf_size) const;

  /// Landau waveform generator
  std::vector<short> Landau(size_t wf_size) const;

  /// Toy MC data file generator for a gaussian waveform
  void MakeGausMC(std::string file_name, size_t nentries, size_t wf_size)
  { MakeMC(file_name, nentries, wf_size, fGaus); }

  /// Toy MC data file generator for a landau waveform
  void MakeLandauMC(std::string file_name, size_t nentries, size_t wf_size)
  { MakeMC(file_name, nentries, wf_size, fLandau); }

  short fBaseline; ///< Baseline value (default = 2048)

protected:

  /// Internal function to set waveform values using a function
  void GenWaveform(std::vector<short>& wf,const TF1& func) const;

  /// Internal function to generate MC data file
  void MakeMC(std::string file_name, size_t nentries, size_t wf_size, TF1& func);

protected:
  TF1 fGaus;   ///< Gaussian TF1
  TF1 fLandau; ///< Landau   TF1
};

#endif
/** @} */ // end of doxygen group 

