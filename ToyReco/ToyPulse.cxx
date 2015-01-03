#ifndef TOYPULSE_CXX
#define TOYPULSE_CXX

#include "ToyPulse.h"
#include <cfloat>
ToyPulse::ToyPulse(int   start_time,
		   int   peak_time,
		   int   end_time,
		   float amplitude,
		   float charge)
  : fStartTime (start_time)
  , fPeakTime  (peak_time)
  , fEndTime   (end_time)
  , fAmplitude (amplitude)
  , fCharge    (charge)
{}

void ToyPulse::Reset() 
{
  fStartTime = fPeakTime = fEndTime = -1;
  fAmplitude = fCharge = FLT_MIN;
}

#endif
