/**
 * \file ToyPulse.h
 *
 * \ingroup WaveformToy
 * 
 * \brief Class def header for a class ToyPulse
 *
 * @author kazuhiro
 */

/** \addtogroup WaveformToy

    @{*/
#ifndef TOYPULSE_H
#define TOYPULSE_H

#include <TObject.h>
/**
   \class ToyPulse
   User defined class ToyPulse ... these comments are used to generate
   doxygen documentation!
 */
class ToyPulse : public TObject{

public:

  /// Default constructor
  ToyPulse(){ Reset(); }

  /// Alternative constructor
  ToyPulse(int   start_time,
	   int   peak_time,
	   int   end_time,
	   float amplitude,
	   float charge);

  /// Default destructor
  virtual ~ToyPulse(){}

  /// Initializer
  void Reset();

  int   fStartTime; ///< pulse start time
  int   fPeakTime;  ///< pulse peak  time
  int   fEndTime;   ///< pulse end   time
  float fAmplitude; ///< pulse peak amplitude
  float fCharge;    ///< pulse region's integral of an waveform

  ClassDef(ToyPulse,1)
};

#endif
/** @} */ // end of doxygen group 

