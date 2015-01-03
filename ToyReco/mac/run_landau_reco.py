import ROOT, sys
from ROOT import TCanvas, ToyGenerator, ToyPulseReco
import iit_example as iit

# create TCanvas
canvas = TCanvas("canvas","",600,500)
canvas.SetRightMargin  (0.08)
canvas.SetLeftMargin   (0.13)
canvas.SetBottomMargin (0.13)
# generate landau shaped waveform ... size=100, amp=50, peak @ 20, width=5
gen = ToyGenerator()
gen.SetParamsLandau(75,20,4)
landau_wf   = gen.Landau(200)
# generate TH1D from the waveform
landau_hist = iit.waveform_to_hist(landau_wf,"hLandau")
# draw
landau_hist.SetMinimum(2035)
landau_hist.SetMaximum(2150)
landau_hist.Draw()

# reconstruct a pulse
reco_alg    = ToyPulseReco()
pulse_array = reco_alg.Reconstruct(landau_wf)
pulse_hists = []
for x in xrange(pulse_array.size()):
    pulse = pulse_array[x]
    pulse_hists.append( iit.waveform_to_hist(landau_wf,
                                             "hRecoLandau%02d" % x,
                                             "Landau Waveform",
                                             pulse.fStartTime,
                                             pulse.fEndTime) )
    pulse_hists[-1].SetFillStyle(3004)
    pulse_hists[-1].SetFillColor(ROOT.kRed)
    pulse_hists[-1].Draw("sames")

canvas.Update()
print
print 'Hit return to proceed.'
print
sys.stdin.readline()

# Animation
for x in xrange(200):

    gen.SetParamsLandau(75, 20+x*0.5, 4)
    landau_wf1 = gen.Landau(200)
    gen.SetParamsLandau(50, 120+x*0.5, 4)
    landau_wf2 = gen.Landau(200)
    for y in xrange(landau_wf1.size()):
        if landau_wf2[y] > 2048:
            landau_wf1[y] += (landau_wf2[y]-2048)

    landau_hist = iit.waveform_to_hist(landau_wf1,
                                       "hLandau%d" % x,
                                       "Landau Mean @ %s" % "{:3.1f}".format(20+x*0.5))
    landau_hist.SetMinimum(2035)
    landau_hist.SetMaximum(2150)
    canvas.cd()
    landau_hist.Draw()

    pulse_array = reco_alg.Reconstruct(landau_wf1)
    pulse_hists = []
    for y in xrange(pulse_array.size()):
        pulse = pulse_array[y]
        pulse_hists.append( iit.waveform_to_hist(landau_wf1,
                                                 "hRecoLandau%03d_%02d" % (x,y),
                                                 "Landau Waveform",
                                                 pulse.fStartTime,
                                                 pulse.fEndTime) )
        pulse_hists[-1].SetFillStyle(3004)
        pulse_hists[-1].SetFillColor(ROOT.kRed)
        pulse_hists[-1].Draw("sames")

    canvas.Update()
