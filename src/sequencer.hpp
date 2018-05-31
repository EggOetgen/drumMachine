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
//#include "ofxGui.h"
#include "drumSynth.hpp"
#include "ofxImGui.h"

class sequencer{


public:
    sequencer();
    
    void display();
    double play();
    void step(int playHead);
    void update();
    

    static const int numChannels = 8;
     
    drumSynth channels[numChannels];
    bool steps[16][numChannels];
    bool mutes[numChannels];

    bool randomise = false;
    bool clear = false;
    ofxImGui::Gui gui;

    int tempo;
    float gain;
    
    
    //arrays for storing the variables for each synth!
    float frequencies[numChannels], modAmounts[numChannels], ampEnvAtks[numChannels], ampEnvRlss[numChannels], modEnvAtks[numChannels], modEnvRlss[numChannels], noiseEnvAtks[numChannels],noiseEnvRlss[numChannels], pitchMixs[numChannels], noiseMixs[numChannels], toneMixs[numChannels] ;
    

};