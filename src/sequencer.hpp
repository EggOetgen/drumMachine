//
//  sequencer.hpp
//  kickMachine
//
//  Created by Edmund Oetgen on 23/11/2017.
//
//
#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"
#include "drumSynth.hpp"
#include "ofxImGui.h"

class sequencer{


public:
    sequencer();
    
    void display();
    double play();
    void step(int playHead);
    void update();
    
//    drumSynth chanOne;
//    drumSynth chanTwo;
//    drumSynth chanThree;
//    drumSynth chanFour;
    static const int numChannels = 8;
     
    drumSynth channels[numChannels];
    bool steps[16][numChannels];
    ofxImGui::Gui gui;

    int tempo;
    float gain;
    
    
    
    float frequencies[numChannels], modAmounts[numChannels], ampEnvAtks[numChannels], ampEnvRlss[numChannels], modEnvAtks[numChannels], modEnvRlss[numChannels], noiseEnvAtks[numChannels],noiseEnvRlss[numChannels], pitchMixs[numChannels], noiseMixs[numChannels], toneMixs[numChannels] ;
    
//    ofxIntSlider tempo;
//    ofxFloatSlider gain;
//    ofxFloatSlider frequency;
//    ofxFloatSlider modAmount;
//    ofxFloatSlider ampEnvAtk;
//    ofxFloatSlider ampEnvRls;
//    ofxFloatSlider modEnvAtk;
//    ofxFloatSlider modEnvRls;
//    ofxFloatSlider noiseEnvAtk;
//    ofxFloatSlider noiseEnvRls;
//    ofxFloatSlider pitchMix;
//    ofxFloatSlider noiseMix;
//    ofxFloatSlider toneMix;
//    ofxPanel gui;

};