 REquires openframeworks, ofxMaxim and ofxImGui
 
 A sequencable drum synthesiser. It consists of eight channels, and can create 
 16 step sequences. Each channel can be adjusted individually, and is capable 
 or creating a large range of different sounds. The architecture of the project
 consists of a sequencer class which controls 8 instances of a drumSynth class. 
 The drumSynth class has two oscillators, one sine and one saw, as well as a 
 noise generator. The pitch of the oscillators and the amplitude of the 
 oscillators and the noise generator can all be modulated via envelopes.
 There is also adjustable parameters for the attack and release of these
 envelopes, the frequency of the osicllators, the overall amplitude and the mix
 between the sine wave and saw wave. The sequencer class manages synthesiser
 synths with a gui, with drop down menus to adjust each parameter individually. 
 It also stores the sequences to pass to the synths and controls the tempo and 
 overall volume of the synthesiser. Sequences can be programmed in using the 
 8x16 button grid, and there is also buttons to clear the current sequence or
 randomise a new one.