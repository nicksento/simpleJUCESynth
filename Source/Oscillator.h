/*
  ==============================================================================

    Oscillator.h
    Created: 13 Mar 2020 11:39:13am
    Author:  Theodore

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/*
*/
class Oscillator    : public Component,
                        private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;
    
private:
    ComboBox oscMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    
    SynthFrameworkAudioProcessor& processor;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
