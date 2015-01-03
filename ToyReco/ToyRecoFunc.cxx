#ifndef TOYRECOFUNC_CXX
#define TOYRECOFUNC_CXX

#include "ToyRecoFunc.h"

TH1D* AnaTree(std::string file_name)
{
  TH1D* h = nullptr;
  auto ch = new TChain("wf_tree","");
  auto wf = new std::vector<short>();
  ch->SetBranchAddress("toy_wf",&wf);
  ch->AddFile(file_name.c_str());
  if(!ch->GetEntries()){
    std::cerr << "File w/ toy_mc TTree not found..." << std::endl;
    return h;
  }

  ToyPulseReco alg;
  for(size_t entry=0; (int)entry < ch->GetEntries(); ++entry) {
    ch->GetEntry(entry);
    for(auto const& p : alg.Reconstruct(*wf)) {

      if(!h) h = new TH1D("hPeakTime","Peak Time Distribution; Time-Tick; Pulses",
			  wf->size(),-0.5,wf->size()-0.5);
      h->Fill(p.fPeakTime);
    }
  }
  return h;
}

void RecoTree(std::string file_name)
{
  auto ch = new TChain("wf_tree","");
  auto wf = new std::vector<short>();
  ch->SetBranchAddress("toy_wf",&wf);
  ch->AddFile(file_name.c_str());
  if(!ch->GetEntries()){
    std::cerr << "File w/ toy_mc TTree not found..." << std::endl;
    return;
  }

  TFile out_file(Form("out_%s",file_name.c_str()),"RECREATE");
  auto out_tree = new TTree("pulse_tree","toy reconstruction result");
  auto out_data = new std::vector<ToyPulse_t>();
  out_tree->Branch("toy_pulse","std::vector<ToyPulse_t>",&out_data);

  ToyPulseReco alg;
  alg.Threshold(2050);

  for(size_t entry = 0; (int)entry < ch->GetEntries(); ++entry) {
    ch->GetEntry(entry);
    alg.Reconstruct(*out_data,*wf);
    out_tree->Fill();
  }

  out_file.cd();
  out_tree->Write();
  out_file.Close();

  delete ch;
  delete wf;
}

#endif
