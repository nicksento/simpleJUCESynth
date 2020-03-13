/*
  ==============================================================================

    SynthVoice.h
    Created: 12 Mar 2020 7:17:35pm
    Author:  Theodore

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "Maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
    
    
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr; //trying to cast sound as class synthsound. if that cast is successful then this is going to return true
    }
    //==============================================================================
    void getParam (float* attack)
    {
        env1.setAttack(double (*attack));
        
    }
    
    //==============================================================================
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        //what happens when we hit a note to our keyboard
        env1.trigger = 1;
        level = velocity;
        //class midi message
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        //std::cout << midiNoteNumber << std::endl;
        
    }
    //==============================================================================
    void stopNote (float velocity, bool allowTailOff) override
    {
        env1.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0){
            clearCurrentNote();
        }
        //level = 0;
        
    }
    //==============================================================================
    void pitchWheelMoved (int newPitchWheelValue) override
    {
        
    }
    //==============================================================================
    void controllerMoved (int controllerNumber, int newControllerValue) override
    {
        
    }
    //==============================================================================
    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override
    {
        
        
        
        
        for (int sample = 0; sample < numSamples; ++sample)
        {
           // double theWave = osc1.sinewave(frequency);
           // double theSound = env1.adsr(setOscType(), env1.trigger) * level;
            
            
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, setFilter()* 0.3);
            }
            
            ++startSample;
        }
    }
    //==============================================================================
    void getEnvelopeParams(float* attack,float* decay, float* sustain, float* release)
        {
            env1.setAttack(*attack);
            env1.setDecay(*decay);
            env1.setSustain(*sustain);
            env1.setRelease(*release);
            
            
        }
    //==============================================================================
    double setEnvelope()
    {
        return env1.adsr(setOscType(), env1.trigger) * level;
    }
    //==============================================================================
    void getOscType(float* selection)
        {
            theWave = *selection;
        }
    //==============================================================================
    double setOscType ()
    {
        if (theWave == 0)
        {
            return osc1.sinewave(frequency);
        }
        
        if (theWave == 1)
        {
            return osc1.saw(frequency);
        }
        
        if (theWave == 2)
        {
            return osc1.square(frequency);
        }
        
        else
        {
            return osc1.sinewave(frequency);
        }
    }
    //==============================================================================
    void getFilterParams(float* filterType, float* filterCutoff, float* filterRes)
    {
        filterChoice = *filterType;
        cutoff = *filterCutoff;
        resonance = *filterRes;
    }
    //==============================================================================
    double setFilter()
    {
        if (filterChoice == 0)
        {
            return filter1.lores(setEnvelope(), cutoff, resonance);
        }
        
        if (filterChoice == 1)
        {
            return filter1.hires(setEnvelope(), cutoff, resonance);
        }
        
        
        if (filterChoice == 2)
        {
            return filter1.bandpass(setEnvelope(), cutoff, resonance);
        }
                
        else
        {
            return filter1.lores(setEnvelope(), cutoff, resonance);
        }
    }
    //==============================================================================
    
private:
    double level;
    double frequency;
    int theWave;
    
    int filterChoice;
    float cutoff;
    float resonance;
    
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;
    
};
