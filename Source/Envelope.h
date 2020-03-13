/*
  ==============================================================================

    Envelope.h
    Created: 13 Mar 2020 1:38:18pm
    Author:  Theodore

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
    
   

private:
    
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;
    
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal;
    
    
    SynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
