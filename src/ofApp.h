#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"
#include "drumSynth.hpp"
#include "sequencer.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioOut(float * output, int bufferSize, int nChannels);
        void audioIn(float * input, int bufferSize, int nChannels);

    
    float 	* lAudioOut; /* outputs */
    float   * rAudioOut;
    
    float * lAudioIn; /* inputs */
    float * rAudioIn;
    
    vector <float> lAudio;
    vector <float> rAudio;
    double outputs[2];
    
    double audOut;

    ofxIntSlider tempo;
    ofxFloatSlider gain;
    ofxFloatSlider frequency;
    ofxFloatSlider modAmount;
    ofxFloatSlider ampEnvAtk;
    ofxFloatSlider ampEnvRls;
    ofxFloatSlider modEnvAtk;
    ofxFloatSlider modEnvRls;
    ofxFloatSlider noiseEnvAtk;
    ofxFloatSlider noiseEnvRls;
    ofxFloatSlider pitchMix;
    ofxFloatSlider noiseMix;
    ofxFloatSlider toneMix;
    ofxPanel gui;
    
    ofxButton buttOne;
     ofxButton buttTwo;
     ofxButton buttThree;
     ofxButton buttFour;
    ofxButton buttFive;
     ofxButton buttSix;
     ofxButton buttSeven;
     ofxButton buttEight;
     ofxButton buttNine;
     ofxButton buttTen;
     ofxButton buttEleven;
     ofxButton buttTwelve;
     ofxButton buttThirteen;
     ofxButton buttFourteen;
     ofxButton buttFifteen;
     ofxButton buttSixteen;
    
    
    
    int sampleRate, bufferSize;
    int trigger;
    
    int playHead;
    
    maxiClock benKlock;
    
    maxiKick kick;
    
    drumSynth test;
 //   drumSynth test = drumSynth(200, 1,0.7, 1,  1, 0, 0, 20000, 0, 10, 0, 10);
    
    vector<drumSynth*> tests;
    
    sequencer testSeq;
};
