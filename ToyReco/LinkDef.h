//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class ToyPulseReco+;
#pragma link C++ class ToyPulse+;
#pragma link C++ class std::vector<ToyPulse>+;
#pragma link C++ function AnaTree(string)+;
#pragma link C++ function RecoTree(string)+;
#pragma link C++ class ToyPulseRecoTemplate<short>+;
#pragma link C++ class ToyPulseRecoTemplate<float>+;
//ADD_NEW_CLASS ... do not change this line
#endif






