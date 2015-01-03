import sys
from ROOT import TCanvas, ToyGenerator
import iit_example as iit

# create TCanvas
canvas = TCanvas("canvas","",600,500)
canvas.SetRightMargin  (0.08)
canvas.SetLeftMargin   (0.13)
canvas.SetBottomMargin (0.13)
# generate gaussian shaped waveform ... size=100, amp=50, peak @ 20, width=5
gen = ToyGenerator()
gen.SetParamsGaus(50,20,5)
gaus_wf = gen.Gaussian(100)
# generate TH1D from the waveform
gaus_hist = iit.waveform_to_hist(gaus_wf,"hGaus")
# draw
gaus_hist.SetMinimum(2035)
gaus_hist.SetMaximum(2120)
gaus_hist.Draw()
canvas.Update()

print
print 'Hit return to proceed.'
print
sys.stdin.readline()

# Animation
for x in xrange(200):

    gen.SetParamsGaus(50,20+x*0.5,5)
    gaus_wf   = gen.Gaussian(200)
    gaus_hist = iit.waveform_to_hist(gaus_wf,
                                     "hGaus%d" % x,
                                     "Gaussian Mean @ %s" % "{:3.1f}".format(20+x*0.5))
    gaus_hist.SetMinimum(2035)
    gaus_hist.SetMaximum(2120)

    canvas.cd()
    gaus_hist.Draw()
    canvas.Update()
