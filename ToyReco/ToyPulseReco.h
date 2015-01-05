/**
 * \file ToyPulseReco.h
 *
 * \ingroup WaveformToy
 * 
 * \brief Class def header for a class ToyPulseReco
 *
 * @author kazuhiro
 */

/** \addtogroup WaveformToy

    @{*/
#ifndef TOYPULSERECO_H
#define TOYPULSERECO_H

#include <vector>
#include "ToyPulse.h"
/**
   \class ToyPulseReco
   @brief A simple toy pulse reconstruction algorithm class
   This algorithm finds a pulse from an waveform by finding the start and the end point.\n
   The "start" is defined by a part of waveform that comes across the set threshold with a positive slope. \n
   The "end" is defined by a part of waveform that comes across the set threshold with a negative slope.\n
   The "peak time" is set at the maximum ADC count timing within the pulse window.\n
   The "charge" is set as an integral of all ADC values within the pulse window.\n
   The "amplitude" is set as the maximum ADC value within the pulse window.\n
 */
class ToyPulseReco{

public:
  /// Default constructor
  ToyPulseReco() : fThreshold (2050) {}

  /// Default destructor
  virtual ~ToyPulseReco(){}

private:
  float fThreshold; ///< Pulse reconstruction threshold

public:
  /// Threshold setter
  void Threshold(float v) { fThreshold = v; }

  /// Threshold accessor
  float Threshold() const { return fThreshold; }

  /// Find pulses and return
  std::vector<ToyPulse> Reconstruct (const std::vector<short>& waveform) const
  { std::vector<ToyPulse> res; Reconstruct(res,waveform); return res; }
  
  /// Find pulses and fill
  void Reconstruct (std::vector<ToyPulse> &result,
		    const std::vector<short>& waveform) const;

};

#endif
/** @} */ // end of doxygen group 

