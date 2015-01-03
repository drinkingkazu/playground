import ROOT,sys
from ROOT import TCanvas, ToyGenerator, ToyPulseReco
import iit_example as iit 

# create TCanvas
canvas = TCanvas("canvas","",600,500)
canvas.SetRightMargin  (0.08)
canvas.SetLeftMargin   (0.13)
canvas.SetBottomMargin (0.13)
# generate gaus shaped waveform ... size=100, amp=50, peak @ 20, width=5
gen = ToyGenerator()
gen.SetParamsGaus(75,20,5)
gaus_wf   = gen.Gaussian(200)
# generate TH1D from the waveform
gaus_hist = iit.waveform_to_hist(gaus_wf,"hGaussian")
# draw
gaus_hist.SetMinimum(2035)
gaus_hist.SetMaximum(2150)
gaus_hist.Draw()

# reconstruct a pulse
reco_alg    = ToyPulseReco()
pulse_array = reco_alg.Reconstruct(gaus_wf)
pulse_hists = []
for x in xrange(pulse_array.size()):
    pulse = pulse_array[x]
    pulse_hists.append( iit.waveform_to_hist(gaus_wf,
                                             "hRecoGaussian%02d" % x,
                                             "Gaussian Waveform",
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

    gen.SetParamsGaus(75, 20+x*0.5, 4)
    gaus_wf1 = gen.Gaussian(200)
    gen.SetParamsGaus(50, 120+x*0.5, 4)
    gaus_wf2 = gen.Gaussian(200)
    for y in xrange(gaus_wf1.size()):
        if gaus_wf2[y] > 2048:
            gaus_wf1[y] += (gaus_wf2[y] - 2048)

    gaus_hist = iit.waveform_to_hist(gaus_wf1,
                                     "hGaussian%d" % x,
                                     "Gaussian Mean @ %s" % "{:3.1f}".format(20+x*0.5))
    gaus_hist.SetMinimum(2035)
    gaus_hist.SetMaximum(2150)
    canvas.cd()
    gaus_hist.Draw()

    pulse_array = reco_alg.Reconstruct(gaus_wf1)
    pulse_hists = []
    for y in xrange(pulse_array.size()):
        pulse = pulse_array[y]
        pulse_hists.append( iit.waveform_to_hist(gaus_wf1,
                                                 "hRecoGaussian%03d_%02d" % (x,y),
                                                 "Gaussian Waveform",
                                                 pulse.fStartTime,
                                                 pulse.fEndTime) )
        pulse_hists[-1].SetFillStyle(3004)
        pulse_hists[-1].SetFillColor(ROOT.kRed)
        pulse_hists[-1].Draw("sames")

    canvas.Update()
