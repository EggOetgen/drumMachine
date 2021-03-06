//
//  drumSynth.hpp
//  kickMachine
//
//  Created by Edmund Oetgen on 21/11/2017.
//
//

#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
//#include "ofxGui.h"

class drumSynth{
    
public:
  
    //default values, close enough to a kick
       drumSynth(double freq = 40, double pma = 1.5, float gain_ =0.5, float om = 0.9, float tm = 1.0, float nm = 0.1, float oa = 0, float oR = 5000, float pa = 0, float pr = 10, float na = 0, float nr = 5);
    
    double play(bool isMute);
    void trigger();
    void update();
    void setFrequency(double newFreq);
    void setGain(float newGain);
    void setModAmount(double modAmount);
    void setOscEnv(double attack, double decay, double sustain, double release);
    void setModEnv(double attack, double decay, double sustain, double release);
    void setNoiseEnv(double attack, double decay, double sustain, double release);
    void setOscMix(float mix);
    void setNoiseMix(float mix);
    void setToneMix(float mix);
   
    maxiOsc sine;
    maxiOsc saw;
    maxiOsc noise;
    maxiOsc FM;

    maxiEnv oscAmpEnv;
    maxiEnv noiseAmpEnv;
    
    maxiEnv pitchMod;

    double frequency;
    
    double oscEnvOut;
    double pitchModOut;
    double pitchModAmount;
    double noiseEnvOut;
    
    double output;
    
    float gain;
    
    float oscMix;
    float noiseMix;
    float toneMix;
   
    //initial sequence
    int sequence [16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
};