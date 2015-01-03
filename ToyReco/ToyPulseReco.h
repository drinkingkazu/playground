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
   User defined class ToyPulseReco ... these comments are used to generate
   doxygen documentation!
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

