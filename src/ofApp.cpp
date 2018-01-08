#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /* This is stuff you always need.*/
    
    ofSetFrameRate(60);
    
    ofSetVerticalSync(true);
//    gui.setup();
//    gui.add(tempo.setup("tempo",128,60,2510));
//    gui.add(gain.setup("Volume",0.5,0,1));
//    gui.add(frequency.setup("pitch",50,20,500));
//    gui.add(modAmount.setup("modAmount",1.5,1,5));
//    gui.add(ampEnvAtk.setup("Amp Attack",0,0,1000));
//    gui.add(ampEnvRls.setup("Amp Relase",5000,0,10000));
//    gui.add(modEnvAtk.setup("Mod Attack",0,1,100));
//    gui.add(modEnvRls.setup("Mod Relase",60,1,1000));
//    gui.add(noiseEnvAtk.setup("noise Attack",0,0,100));
//    gui.add(noiseEnvRls.setup("noise Relase",10,0,100));
//    gui.add(pitchMix.setup("WaveShape",0.8,0,1));
//    gui.add(noiseMix.setup("noise",0.2,0,1));
//    gui.add(toneMix.setup("tone level",0.2,0,1));
//    gui.add(buttOne.setup("1"));

    sampleRate 	= 44100; /* Sampling Rate */
    bufferSize	= 1024; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
   // test = drumSynth(200, 1,0.7, 1,  1, 0, 0, 20000, 0, 10, 0, 10);
//    int numOfDrums = 3;
//    
//    for(int i = 0; i < numOfDrums; i++){
//        drumSynth* drum = new drumSynth();
//        tests.push_back(drum);
//    }

    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    
    benKlock.setTempo(132      );
    benKlock.setTicksPerBeat(4);
    
    playHead = 0;
    
 
//    int snare[] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
//
//    memcpy(tests[1]->sequence, snare, 16);
//
//    int other[] = {0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0};
//    
//    memcpy(tests[2]->sequence, other, 16);

    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
 //   cout<<playHead<<endl;

    benKlock.setTempo(testSeq.tempo);
   
    
//    for(int i = 0; i < tests.size(); i++){
//        tests[i]->update();
//        
//    }
//    tests[1]->frequency*=10;
//    tests[2]->noiseMix*=1.1;

//    test.setFrequency(frequency);
//    test.setGain(gain);
//    test.setModAmount(modAmount);
//    test.setOscEnv(ampEnvAtk, 1,1, ampEnvRls);
//    test.setModEnv(modEnvAtk, 1,1, modEnvRls);
//    test.setNoiseEnv(noiseEnvAtk, 1,1, noiseEnvRls);
//    test.setOscMix(pitchMix);
//    test.setNoiseMix(noiseMix);
//    test.setToneMix(toneMix);

    testSeq.update();
    cout<<testSeq.modAmounts[0] <<endl;
//    for(int i =0; i < 16; i++){
//        cout<<testSeq.chanTwo.sequence[i];
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){

   // gui.draw();
    testSeq.display();
   // test.display();
//    for(int i = 0; i < tests.size(); i++){
//                tests[i]->display();
//    }

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    for (int i = 0; i < bufferSize; i++){
        
        benKlock.ticker();
        
        if (benKlock.tick) {
            playHead++;
            playHead%=16;

//            if(test.sequence[playHead]  ==1){
//            test.trigger();
//            }
            testSeq.step(playHead);
          //  kick.trigger();
        }
//        
//        if (benKlock.tick) {
//            playHead++;
//            playHead%=16;
//            
//            for(int i = 0; i < tests.size(); i++){
//               
//
//            if(tests[i]->sequence[playHead]  ==1){
//                tests[i]->trigger();
//            }
//            //  kick.trigger();
//        }
//        }

        
       // audOut = test.play();
        
        audOut = testSeq.play();
//        for(int i = 0; i < tests.size(); i++){
//            audOut += (tests[i]->play()*0.33);
//        }
//        if(audOut >=0.9) audOut = 0.7;
        //audOut = kick.play();
        output[i*nChannels    ] = audOut; /* You may end up with lots of outputs. add them here */
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
