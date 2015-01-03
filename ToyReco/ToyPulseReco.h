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

  /// Threshold setter
  void Threshold(float v) { fThreshold = v; }

  /// Threshold accessor
  float Threshold() const { return fThreshold; }

  /// Find pulses and fill
  void Reconstruct (std::vector<ToyPulse_t> &result,
		    const std::vector<short>& waveform) const;

  /// Find pulses and return
  std::vector<ToyPulse_t> Reconstruct (const std::vector<short>& waveform) const
  { std::vector<ToyPulse_t> res; Reconstruct(res,waveform); return res; }
  
private:

  float fThreshold; ///< Pulse reconstruction threshold

};

#endif
/** @} */ // end of doxygen group 

