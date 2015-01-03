#ifndef TOYPULSERECO_CXX
#define TOYPULSERECO_CXX

#include "ToyPulseReco.h"

void ToyPulseReco::Reconstruct(std::vector<ToyPulse>& result,
			       const std::vector<short>& waveform) const
{

  result.clear();
  if(!waveform.size()) return;

  ToyPulse pulse;

  pulse.fStartTime = ( fThreshold <= waveform[0] ? 0 : -1 );
  
  for(size_t i=0; i<waveform.size()-1; ++i) {

    auto const& v1 = waveform[i];
    auto const& v2 = waveform[i+1];

    pulse.fCharge += v1;
    if(pulse.fAmplitude < v1) {
      pulse.fPeakTime  = i;
      pulse.fAmplitude = v1;
    }

    // Inspect for pulse start
    if(v1 < fThreshold && fThreshold <= v2) {
      pulse.Reset();
      pulse.fStartTime = i+1;
      pulse.fCharge = 0;
    }

    // Inspect for pulse end
    if(v2 < fThreshold && fThreshold <= v1) {
      pulse.fEndTime = i;
      result.push_back(pulse);
      pulse.Reset();
    }
  }
  if(pulse.fStartTime >=0) {
    pulse.fEndTime = waveform.size()-1;
    result.push_back(pulse);
  }
}

#endif
