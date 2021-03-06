//
//  drumSynth.cpp
//  kickMachine
//
//  Created by Edmund Oetgen on 21/11/2017.
//
//

#include "drumSynth.hpp"

drumSynth::drumSynth(double freq, double pma, float gain_, float om, float tm, float nm, float oa, float oR, float pa, float pr, float na, float nr){

    //set all the parameters!
    
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
    
  
}

double drumSynth::play(bool isMute){

    //check wether or not to play it
    if(!isMute){
        
        //running the envelopes
    oscEnvOut = oscAmpEnv.adsr(1., oscAmpEnv.trigger);
    pitchModOut = pitchMod.adsr(pitchModAmount, pitchMod.trigger);
    noiseEnvOut = noiseAmpEnv.adsr(1., noiseAmpEnv.trigger);

  
        //set mix between the two waveforms
    float sineMix = oscMix;
    float sawMix = (1.-oscMix);
   
        //all our outputs
    double sineOutput = sine.sinewave(frequency*(1+pitchModOut))*oscEnvOut;
    double sawOutput = saw.triangle(frequency*(1+pitchModOut))*oscEnvOut;
    double noiseOutput = noise.noise()*noiseEnvOut;
    
        //add 'em uo
    output = (((sineMix*sineOutput) + (sawMix*sawOutput)) * toneMix) + (noiseOutput * noiseMix);

        //reset our tiggers
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
    }else{
        //don't want to output anything if mute
        return 0;
    }
}

void drumSynth::trigger(){
    //go go go!
    oscAmpEnv.trigger = 1;
    pitchMod.trigger =1;
    noiseAmpEnv.trigger = 1;

}

//functions for assigning all our parameteers!
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






