/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"
#include "Filter.h"

//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor

{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    
    
private:
    SynthFrameworkAudioProcessor& processor;
    
    Oscillator oscGui;
    Envelope envGui;
    Filter filterGui;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
