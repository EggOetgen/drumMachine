#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /* Starndard Maxi Stuff*/
    
    ofSetFrameRate(60);
    
    ofSetVerticalSync(true);
    sampleRate 	= 44100;
    bufferSize	= 1024;

    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    //set the initial tempo
    benKlock.setTempo(132      );
    benKlock.setTicksPerBeat(4);
    
    playHead = 0;
    
 

    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
    

}

//--------------------------------------------------------------
void ofApp::update(){


    benKlock.setTempo(testSeq.tempo);


    testSeq.update();
   }

//--------------------------------------------------------------
void ofApp::draw(){

   
    testSeq.display();
 

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    audOut = 0;
    for (int i = 0; i < bufferSize; i++){
        
        benKlock.ticker();
        
        if (benKlock.tick) {
            playHead++;
            playHead%=16;

            testSeq.step(playHead);
                  }
        audOut = testSeq.play();
        output[i*nChannels    ] = audOut;
        output[i*nChannels + 1] = audOut;

    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   // cout <<key <<endl;

  //  test.randomisePar();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

  
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
