import sys
from ROOT import TCanvas, ToyGenerator
import iit_example as iit

# create TCanvas
canvas = TCanvas("canvas","",600,500)
canvas.SetRightMargin  (0.08)
canvas.SetLeftMargin   (0.13)
canvas.SetBottomMargin (0.13)
# generate landau shaped waveform ... size=100, amp=50, peak @ 20, width=5
gen = ToyGenerator()
gen.SetParamsLandau(50,20,5)
landau_wf = gen.Landau(200)
# generate TH1D from the waveform
landau_hist = iit.waveform_to_hist(landau_wf,"hLandau")
# draw & save
landau_hist.SetMinimum(2035)
landau_hist.SetMaximum(2120)
landau_hist.Draw()
canvas.Update()

print
print 'Hit return to proceed.'
print
sys.stdin.readline()

# Animation
for x in xrange(200):

    gen.SetParamsLandau(50,20+x*0.5,5)
    landau_wf   = gen.Landau(200)
    landau_hist = iit.waveform_to_hist(landau_wf,
                                       "hLandau%d" % x,
                                       "Landau Mean @ %s" % "{:3.1f}".format(20+x*0.5))
    landau_hist.SetMinimum(2035)
    landau_hist.SetMaximum(2120)

    canvas.cd()
    landau_hist.Draw()
    canvas.Update()
