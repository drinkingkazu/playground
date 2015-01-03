#ifndef TOYGENERATOR_CXX
#define TOYGENERATOR_CXX

#include "ToyGenerator.h"

ToyGenerator::ToyGenerator()
  : fBaseline (2048)
  , fGaus     ("fGaus","gaus")
  , fLandau   ("fLandau","[0]*(TMath::Landau(x,[1],[2],0))")
{}

void ToyGenerator::SetParamsLandau(double amp, double mean, double width)
{
  fLandau.SetParameters(1,mean,width);
  fLandau.SetParameter(0,amp/fLandau.Eval(mean));
}

std::vector<short> ToyGenerator::Gaussian(size_t wf_size) const
{ 
  std::vector<short> res(wf_size,0); 
  GenWaveform(res,fGaus); 
  return res; 
}

std::vector<short> ToyGenerator::Landau(size_t wf_size) const
{ 
  std::vector<short> res(wf_size,0); 
  GenWaveform(res,fLandau); 
  return res; 
}

void ToyGenerator::GenWaveform(std::vector<short>& wf,
			       const TF1& func) const
{
  for(size_t i=0; i<wf.size(); ++i)

    wf[i] = fBaseline + (short)(func.Eval(i+0.5));
}

void ToyGenerator::MakeMC(std::string file_name, size_t nentries, size_t wf_size, TF1& func)
{
  // Create output file
  TFile fout(file_name.c_str(),"RECREATE");
  // Create TTree to hold output data product
  TTree* out_tree = new TTree("wf_tree","toy waveform mc file");
  // Create output data product
  std::vector<short> wf(wf_size,0);
  // Attach output data product to TTree
  out_tree->Branch("toy_wf","std::vector<short>",&wf);

  // Generate waveform
  double mean  = func.GetParameter(1);
  double sigma = func.GetParameter(2);
  for(size_t i=0; i<nentries; ++i) {
    // Generate randomized mean value
    double rand_mean = gRandom->Gaus( mean, sigma );
    // Set randomized mean value and generate waveform
    func.SetParameter(1,rand_mean);
    GenWaveform(wf,func);
    // Store
    out_tree->Fill();
  }
  // Write & close
  out_tree->Write();
  fout.Close();
}

#endif
