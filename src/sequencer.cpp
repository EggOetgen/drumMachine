//
//  sequencer.cpp
//  kickMachine
//
//  Created by Edmund Oetgen on 23/11/2017.
//
//
#include "sequencer.hpp"

sequencer::sequencer(){
    tempo = 132;
    gain = 0.5;
    
    channels[0] = drumSynth();
    channels[1] = drumSynth(260, 3.66, 0.5, 0.75, 0.075, 0.815, 0, 750, 0, 16,  0, 44.5) ;
    channels[2] = drumSynth(260, 3.66, 0.5, 0.75, 0.075, 0.815, 0, 750, 0, 16,  0, 44.5) ;
    channels[3] = drumSynth(128,  1.5, 0.5, 0.75, 0.075,     0, 0, 750, 0, 16,  0, 44.5) ;
    channels[4] = drumSynth(128,  1.5, 0.5, 0.75, 0.075,     0, 0, 750, 0, 16,  0, 44.5) ;
    channels[5] = drumSynth(260, 3.66, 0.5, 0.75, 0.075, 0.815, 0, 750, 0, 16,  0, 44.5) ;
    channels[6] = drumSynth(260, 3.66, 0.5, 0.75, 0.075, 0.815, 0, 750, 0, 16,  0, 44.5) ;
    channels[7] = drumSynth(128,  1.5, 0.5, 0.75, 0.075,     0, 0, 750, 0, 16,  0, 44.5) ;
   

   
    for(int i = 0; i < numChannels; i++){
        frequencies[i] = channels[i].frequency;
        modAmounts[i] = channels[i].pitchModAmount;
        ampEnvAtks[i] = 0;
        ampEnvRlss[i] = 500;
        modEnvAtks[i] = 0;
        modEnvRlss[i] = 100;
        noiseEnvAtks[i] = 0;
        noiseEnvRlss[i] = 75;
        pitchMixs[i] = channels[i].oscMix;
        noiseMixs[i] = channels[i].noiseMix;
        toneMixs[i] = channels[i].toneMix;
    }

    int chan1Seq[]= { 1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
    memcpy(channels[0].sequence, chan1Seq, sizeof(chan1Seq));
    int chan2Seq[]= { 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
    memcpy(channels[1].sequence, chan2Seq, sizeof(chan2Seq));
    int chan3Seq[]= { 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
    memcpy(channels[2].sequence, chan3Seq, sizeof(chan3Seq));
    int chan4Seq[]= { 0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0};
    memcpy(channels[3].sequence, chan4Seq, sizeof(chan4Seq));
    int chan5Seq[]= { 1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
    memcpy(channels[4].sequence, chan5Seq, sizeof(chan5Seq));
    int chan6Seq[]= { 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
    memcpy(channels[5].sequence, chan6Seq, sizeof(chan6Seq));
    int chan7Seq[]= { 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
    memcpy(channels[6].sequence, chan7Seq, sizeof(chan7Seq));
    int chan8Seq[]= { 0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0};
    memcpy(channels[7].sequence, chan8Seq, sizeof(chan8Seq));
   
    for(int row = 0; row < numChannels; row++){
      
         mutes[row] = false ;

        for(int col = 0; col < 16; col++){
            steps[col][row] = false;
        }
    }
    gui.setup();
}

double sequencer::play(){

    double output = 0;


    output = channels[0].play(mutes[0]) +channels[1].play(mutes[1]) + channels[3].play(mutes[3]) + channels[2].play(mutes[2]) + channels[4].play(mutes[4]) + channels[5].play(mutes[5]) + channels[6].play(mutes[6]) + channels[7].play(mutes[7]);
    if (output > 1) output = 0.7;
    return output;
}

void sequencer::step(int playHead){


    for(int i = 0; i < numChannels; i++){
        if(channels[i].sequence[playHead]  ==1){
            channels[i].trigger();
        }
    }
}

void sequencer::display(){
    gui.begin();
    
   
    {
        ImGui::SliderInt("Tempo", &tempo, 60, 2510);
        ImGui::SliderFloat("Gain", &gain, 0.0f, 1.0f);
        ImGui::Checkbox("Randomise?",&randomise);
        ImGui::Checkbox("Clear",&clear);

        for(int i = 0; i < numChannels; i ++){
            string name = std::to_string(i);
            char const* test = name.c_str();
            if (ImGui::TreeNode(test))
        {
            ImGui::TreePop();
      
            string temp = "Oscillator " + name + " Mute";
            char const* tempChar = temp.c_str();
            ImGui::Checkbox(tempChar,&mutes[i]);

             temp = "Oscillator " + name + " Frequency";
             tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &frequencies[i], 20.0f, 500.0f);
          
            temp = "Oscillator " + name + " Modulation Amount";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &modAmounts[i], 1.0f, 5.0f);
       
            
            temp = "Oscillator " + name + " Attack";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &ampEnvAtks[i], 0.0f, 100000.0f);
            temp = "Oscillator " + name + " Release";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &ampEnvRlss[i], 0.0f, 2000.0f);
            
            
            temp = "Oscillator " + name + " Modulation Attack";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &modEnvAtks[i], 0.0f, 100.0f);
            temp = "Oscillator " + name + " Modulation Release";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &modEnvRlss[i], 0.0f, 1000.0f);
            
            
            temp = "Oscillator " + name + " Noise Attack";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &noiseEnvAtks[i], 0.0f, 1000.0f);
            temp = "Oscillator " + name + " Noise Release";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &noiseEnvRlss[i], 0.0f, 1000.0f);

            
            temp = "Oscillator " + name + " Waveshape";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &pitchMixs[i], 0.0f, 1.0f);
            
            
            temp = "Oscillator " + name + " Noise Mix";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &noiseMixs[i], 0.0f, 1.0f);
            
            
            temp = "Oscillator " + name + " Tone Mix";
            tempChar = temp.c_str();
            ImGui::SliderFloat(tempChar, &toneMixs[i], 0.0f, 1.0f);
        }
        }
        
    
       
        for(int row = 0; row < numChannels; row++){
        for(int col = 0; col < 16; col++){
            
            string rowNum = std::to_string(col);
            string colNum = std::to_string(row);
            string boxNum = rowNum + " " + colNum;
            char const* test = boxNum.c_str();
            ImGui::Checkbox(test,&steps[col][row]);
           if(col != 15) ImGui::SameLine();
        }
        }
        

       
    }

    gui.end();
}

void sequencer::update(){

    
    for(int row = 0; row < numChannels; row++){
        for(int col = 0; col < 16; col++){
            channels[row].sequence[col] = steps[col][row];
            
            
            if(randomise){
                steps[col][row] = false;
                float r = ofRandom(1.0);
                if (r<0.2){
                    steps[col][row] = true;
                }
                
            }
            if(clear){
                steps[col][row] = false;
                           }

        }
    }
    randomise = false;
    clear = false;

   
  
    for(int i = 0; i < numChannels; i++){

        channels[i].setGain(gain);
        channels[i].setFrequency(frequencies[i]);
        channels[i].setModAmount(modAmounts[i]);
        channels[i].setOscEnv(ampEnvAtks[i], 1,1, ampEnvRlss[i]);
        channels[i].setModEnv(modEnvAtks[i], 1,1, modEnvRlss[i]);
        channels[i].setNoiseEnv(noiseEnvAtks[i], 1,1, noiseEnvRlss[i]);
        channels[i].setOscMix(pitchMixs[i]);
        channels[i].setNoiseMix(noiseMixs[i]);
        channels[i].setToneMix(toneMixs[i]);
    }


}




