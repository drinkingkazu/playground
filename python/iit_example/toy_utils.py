def waveform_to_hist(wf,
                     name="NoName",title="Waveform in Histogram",
                     start=0, end=-1):
    import ROOT
    from ROOT import TH1D
    # Range of an waveform to make a histogram for
    if end < 0: end = wf.size() - 1
    # Create TH1 histogram to look at the waveform
    hWaveform = TH1D(name,"%s; Time-Tick; Amplitude" % title,
                     wf.size(),-0.5,wf.size()-0.5)
    hWaveform.SetFillStyle(3005)
    hWaveform.SetFillColor(ROOT.kBlue)
    hWaveform.SetLineWidth(2)
    # Fill TH1
    for x in xrange(wf.size()):
        if start <= x and x <= end:
            hWaveform.SetBinContent(x+1, wf[x])
        else:
            hWaveform.SetBinContent(x+1,0)

    # Set TH1 style
    hWaveform.GetYaxis().SetTitleFont(22)
    hWaveform.GetYaxis().SetTitleOffset(1.25)
    hWaveform.GetYaxis().SetTitleSize(0.05)    
    hWaveform.GetYaxis().SetLabelFont(22)
    hWaveform.GetYaxis().SetLabelSize(0.04)

    hWaveform.GetXaxis().SetTitleFont(22)
    hWaveform.GetXaxis().SetTitleOffset(1.1)
    hWaveform.GetXaxis().SetTitleSize(0.05)    
    hWaveform.GetXaxis().SetLabelFont(22)
    hWaveform.GetXaxis().SetLabelSize(0.05)

    return hWaveform

def PyAnaTree(filename):
    h = None
    from ROOT import TChain, TH1D, ToyPulseReco
    ch = TChain("wf_tree","")
    ch.AddFile(filename)
    if not ch.GetEntries():
        sys.stderr.write("File w/ toy_mc TTree not found...\n")
        return h
        
    alg = ToyPulseReco()
    for entry in xrange(ch.GetEntries()):
        ch.GetEntry(entry)
        pulses = alg.Reconstruct(ch.toy_wf)
        for pulse_index in xrange(pulses.size()):
            if not h: h = TH1D("hPeakTime","Peak Time Distribution; Time-Tick; Pulses",
                               ch.toy_wf.size(),-0.5,ch.toy_wf.size()-0.5)
            h.Fill(pulses[pulse_index].fPeakTime)

    return h

