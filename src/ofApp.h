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
    
    /* Starndard Maxi Stuff*/
    

        void audioOut(float * output, int bufferSize, int nChannels);
        void audioIn(float * input, int bufferSize, int nChannels);

    
    float 	* lAudioOut;
    float   * rAudioOut;
    
    float * lAudioIn;
    float * rAudioIn;
    
    vector <float> lAudio;
    vector <float> rAudio;
    double outputs[2];
    
    double audOut;

    
    
    int sampleRate, bufferSize;
    int trigger;
    
    int playHead;
    
    maxiClock benKlock;
    

    sequencer testSeq;
};
