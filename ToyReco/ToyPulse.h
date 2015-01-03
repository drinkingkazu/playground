/**
 * \file ToyPulse.h
 *
 * \ingroup WaveformToy
 * 
 * \brief Class def header for a struct ToyPulse_t
 *
 * @author kazuhiro
 */

/** \addtogroup WaveformToy

    @{*/
#ifndef TOYPULSE_H
#define TOYPULSE_H

#include <TObject.h>
#include <cfloat>

/**
   \class ToyPulse_t
 */
struct ToyPulse_t {

public:

  /// Default constructor
  ToyPulse_t(){ Reset(); }

  /// Alternative constructor
  ToyPulse_t(int   start_time,
	     int   peak_time,
	     int   end_time,
	     float amplitude,
	     float charge)
    : fStartTime ( start_time )
    , fPeakTime  ( peak_time  )
    , fEndTime   ( end_time   )
    , fAmplitude ( amplitude  )
    , fCharge    ( charge     )
  {}

  /// Initializer
  void Reset(){
    fStartTime = fPeakTime = fEndTime = -1;
    fAmplitude = fCharge = FLT_MIN;
  }

  int   fStartTime; ///< pulse start time
  int   fPeakTime;  ///< pulse peak  time
  int   fEndTime;   ///< pulse end   time
  float fAmplitude; ///< pulse peak amplitude
  float fCharge;    ///< pulse region's integral of an waveform
};

#endif
/** @} */ // end of doxygen group 

