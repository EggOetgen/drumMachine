//
//  drumSynth.cpp
//  kickMachine
//
//  Created by Edmund Oetgen on 21/11/2017.
//
//

#include "drumSynth.hpp"

drumSynth::drumSynth(double freq, double pma, float gain_, float om, float tm, float nm, float oa, float oR, float pa, float pr, float na, float nr){

    
    frequency = freq;
    pitchModAmount = pma;
    
    gain = gain_;
    
    oscMix = om;
    toneMix = tm;
    noiseMix = nm;
    
    drumSynth::oscAmpEnv.setAttack(oa);
    drumSynth::oscAmpEnv.setDecay(1);
    drumSynth::oscAmpEnv.setSustain(1);
    drumSynth::oscAmpEnv.setRelease(oR);
    drumSynth::oscAmpEnv.holdtime = 0;
    drumSynth::oscAmpEnv.trigger = 0;
    
    pitchMod.setAttack(pa);
    pitchMod.setDecay(1);
    pitchMod.setSustain(1);
    pitchMod.setRelease(pr);
    pitchMod.holdtime = 0;
    pitchMod.trigger = 0;
    
    noiseAmpEnv.setAttack(na);
    noiseAmpEnv.setDecay(1);
    noiseAmpEnv.setSustain(1);
    noiseAmpEnv.setRelease(nr);
    noiseAmpEnv.holdtime = 1;
    noiseAmpEnv.trigger = 0;
    
  

 
    
//    gui.setup();
//   // gui.add(tempo.setup("tempo",128,60,2510));
//    gui.add(gainS.setup("Volume",0.5,0,1));
//    gui.add(frequencyS.setup("pitch",50,20,500));
//    gui.add(modAmount.setup("modAmount",1.5,1,5));
//    gui.add(ampEnvAtk.setup("Amp Attack",0,0,1000));
//    gui.add(ampEnvRls.setup("Amp Relase",5000,0,10000));
//    gui.add(modEnvAtk.setup("Mod Attack",0,1,100));
//    gui.add(modEnvRls.setup("Mod Relase",60,1,1000));
//    gui.add(noiseEnvAtk.setup("noise Attack",0,0,100));
//    gui.add(noiseEnvRls.setup("noise Relase",10,0,100));
//    gui.add(pitchMix.setup("WaveShape",0.8,0,1));
//    gui.add(noiseMixS.setup("noise",0.2,0,1));
//    gui.add(toneMixS.setup("tone level",0.2,0,1));
//    gui.add(buttOne.setup("1"));
//    

}

double drumSynth::play(){

    oscEnvOut = oscAmpEnv.adsr(1., oscAmpEnv.trigger);
    pitchModOut = pitchMod.adsr(pitchModAmount, pitchMod.trigger);
    noiseEnvOut = noiseAmpEnv.adsr(1., noiseAmpEnv.trigger);

//  
    float sineMix = oscMix;
    float sawMix = (1.-oscMix);
   
    double sineOutput = sine.sinewave(frequency*(1+pitchModOut))*oscEnvOut;
    double sawOutput = saw.triangle(frequency*(1+pitchModOut))*oscEnvOut;
    //double sineOutput = sine.sinewave(frequency*FM.phasor(100000, 3, 0.1))*oscEnvOut;
    double noiseOutput = noise.noise()*noiseEnvOut;
    
    output = (((sineMix*sineOutput) + (sawMix*sawOutput)) * toneMix) + (noiseOutput * noiseMix);

    if(oscAmpEnv.trigger == 1){
        oscAmpEnv.trigger =0;
        
    }
    
    if(pitchMod.trigger == 1){
        pitchMod.trigger =0;
        
    }
    
    if(noiseAmpEnv.trigger == 1){
        noiseAmpEnv.trigger =0;
        
    }

    
   
    return output * gain;

}

void drumSynth::trigger(){
    oscAmpEnv.trigger = 1;
    pitchMod.trigger =1;
    noiseAmpEnv.trigger = 1;

}

void drumSynth::setFrequency(double newFreq){

    frequency = newFreq;

}

void drumSynth::setModAmount(double modAmount){
    
    pitchModAmount = modAmount;
    
}

void drumSynth::setOscEnv(double attack, double decay, double sustain, double release){

    oscAmpEnv.setAttack(attack);
    oscAmpEnv.setDecay(decay);
    oscAmpEnv.setSustain(sustain);
    oscAmpEnv.setRelease(release);
 
}

void drumSynth::setModEnv(double attack, double decay, double sustain, double release){
  
    pitchMod.setAttack(attack);
    pitchMod.setDecay(decay);
    pitchMod.setSustain(sustain);
    pitchMod.setRelease(release);
    
}

void drumSynth::setNoiseEnv(double attack, double decay, double sustain, double release){
    
    noiseAmpEnv.setAttack(attack);
    noiseAmpEnv.setDecay(decay);
    noiseAmpEnv.setSustain(sustain);
    noiseAmpEnv.setRelease(release);
   
}

void drumSynth::setOscMix(float mix){

    oscMix = mix;
}

void drumSynth::setNoiseMix(float mix){
    
    noiseMix = mix;
}

void drumSynth::setToneMix(float mix){
    
    toneMix = mix;
}

void drumSynth::setGain(float newGain){
    
    gain = newGain;
}

void drumSynth::randomiseSeq(){
    
    for(int i = 0; i < 16; i++){
        sequence[i] = (int)ofRandom(2);
    }
}



void drumSynth::update(){
//    
//    setFrequency(frequencyS);
//    setGain(gainS);
//    setModAmount(modAmount);
//    setOscEnv(ampEnvAtk, 1,1, ampEnvRls);
//    setModEnv(modEnvAtk, 1,1, modEnvRls);
//    setNoiseEnv(noiseEnvAtk, 1,1, noiseEnvRls);
//    setOscMix(pitchMix);
//    setNoiseMix(noiseMixS);
//    setToneMix(toneMixS);
}

void drumSynth::randomisePar(){
//frequency = ofRandom(20,100);
//    setFrequency(frequency);
//modAmount = ofRandom(1,5);
//setModAmount(modAmount);
//ampEnvRls = ofRandom(1,10000);
//
//setOscEnv(1, 1,1, ampEnvRls);
//modEnvRls = ofRandom(1,1000);
//setModEnv(1, 1,1, modEnvRls);
//noiseEnvAtk = ofRandom(1,100);
//noiseEnvRls = ofRandom(1,100);
//setNoiseEnv(noiseEnvAtk, 1,1, noiseEnvRls);
//pitchMix = ofRandom(1);
//setOscMix(pitchMix);
//noiseMix = ofRandom(0.2);
//setNoiseMix(noiseMix);
}
