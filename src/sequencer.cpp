//
//  sequencer.cpp
//  kickMachine
//
//  Created by Edmund Oetgen on 23/11/2017.
//
//

  //drumSynth(double freq = 40, double pma = 1.5, float gain_ =0.5, float om = 0.9, float tm = 1.0, float nm = 0.1, float oa = 0, float oR = 5000, float pa = 0, float pr = 10, float na = 0, float nr = 5);
#include "sequencer.hpp"

sequencer::sequencer(){

//     chanOne;
//    chanTwo = drumSynth(260, 3.66, 0.5, 0.75, 0.075, 0.815, 0, 750, 0, 16, 0, 44.5) ;
//    chanThree = drumSynth(0, 0, 0.5, 0, 0, 0.815, 0, 750, 0, 16, 41, 11) ;
//
//    chanFour = drumSynth(128, 1.5, 0.5, 0.75, 0.075, 0, 0, 750, 0, 16, 0, 44.5) ;
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
   

   //float frequencies[numChannels], modAmounts[numChannels], ampEnvAtks[numChannels], ampEnvRlss[numChannels], modEnvAtks[numChannels], modEnvRlss[numChannels], noiseEnvAtks[numChannels],noiseEnvRlss[numChannels], pitchMixs[numChannels], noiseMixs[numChannels], toneMixs[numChannels] ;

    for(int i = 0; i < numChannels; i++){
        frequencies[i] = channels[i].frequency;
        modAmounts[i] = channels[i].pitchModAmount;
        ampEnvAtks[i] = 0;//channels[i].oscAmpEnv.attack;
        ampEnvRlss[i] = 500;//channels[i].oscAmpEnv.release;
        modEnvAtks[i] = 0;//channels[i].pitchMod.attack;
        modEnvRlss[i] = 100;//channels[i].pitchMod.release;
        noiseEnvAtks[i] = 0;//channels[i].noiseAmpEnv.attack;
        noiseEnvRlss[i] = 75;//channels[i].noiseAmpEnv.release;
        pitchMixs[i] = channels[i].oscMix;
        noiseMixs[i] = channels[i].noiseMix;
        toneMixs[i] = channels[i].toneMix;
    }
//    int chan2Seq[]= { 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
//    memcpy(chanTwo.sequence, chan2Seq, sizeof(chan2Seq));
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
//         int chanSeq[]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//         memcpy(channels[row].sequence, chanSeq, sizeof(chanSeq));

        for(int col = 0; col < 16; col++){
            steps[col][row] = false;
        }
    }
    gui.setup();
}

double sequencer::play(){

    double output = 0;
//    
//    if(chanOne.sequence[playHead]  ==1){
//        chanOne.trigger();
//    }
//    if(chanTwo.sequence[playHead]  ==1){
//        chanTwo.trigger();
//    }
//    if(chanOne.sequence[playHead]  ==1){
//        chanOne.trigger();
//    }
//    output = chanOne.play() +chanTwo.play();

    output = channels[0].play() +channels[1].play() + channels[3].play() + channels[2].play() + channels[4].play() + channels[5].play() + channels[6].play() + channels[7].play();
    if (output > 1) output = 0.7;
    return output;
}

void sequencer::step(int playHead){

//    if(chanTwo.sequence[playHead]  ==1){
//        chanTwo.trigger();
//        
//    }
//    if(chanOne.sequence[playHead]  ==1){
//        chanOne.trigger();
//        
//    }
//    if(channels[0].sequence[playHead]  ==1){
//        channels[0].trigger();
//    }
//    if(channels[1].sequence[playHead]  ==1){
//        channels[1].trigger();
//    }
//    if(channels[2].sequence[playHead]  ==1){
//        channels[2].trigger();
//        
//    }
//    if(channels[3].sequence[playHead]  ==1){
//        channels[3].trigger();
//        
//    }
    for(int i = 0; i < numChannels; i++){
        if(channels[i].sequence[playHead]  ==1){
            channels[i].trigger();
        }
    }
}

void sequencer::display(){
    gui.begin();
    
    //In between gui.begin() and gui.end() you can use ImGui as you would anywhere else
    
    // 1. Show a simple window
    {
        ImGui::SliderInt("Tempo", &tempo, 60, 2510);
        ImGui::SliderFloat("Gain", &gain, 0.0f, 1.0f);
        for(int i = 0; i < numChannels; i ++){
            string name = std::to_string(i);
            char const* test = name.c_str();
            if (ImGui::TreeNode(test))
        {
            ImGui::TreePop();
      
            string temp = "Oscillator " + name + " Frequency";
            char const* tempChar = temp.c_str();
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
        //this will change the app background color
      //  ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
       
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
        

        if (ImGui::Button("Another Window"))
        {
            //bitwise OR
           // show_another_window ^= 1;
            
        }
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }

    gui.end();
}

void sequencer::update(){

    
    for(int row = 0; row < numChannels; row++){
        for(int col = 0; col < 16; col++){
            channels[row].sequence[col] = steps[col][row];
        }
    }

    
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




