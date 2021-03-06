/*
  ==============================================================================

    Filter.cpp
    Created: 13 Mar 2020 2:48:38pm
    Author:  Theodore

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    setSize(200, 200);
    
    filterMenu.addItem("Low Pass", 1);
    filterMenu.addItem("High Pass", 2);
    filterMenu.addItem("Band Pass", 3);
    filterMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterMenu);
    filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "filterType", filterMenu);
    
    filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setRange(20.0, 10000.0);
    filterCutoff.setValue(400.0);
    filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterCutoff);
    filterVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "filterCutoff", filterCutoff);
    filterCutoff.setSkewFactor(1000.0);
    
    
    filterRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterRes.setRange(1, 5);
    filterRes.setValue(1);
    filterRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    resVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "filterRes", filterRes);
    addAndMakeVisible(&filterRes);

}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    
    
    Rectangle<float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
    
}

void Filter::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu.setBounds(area.removeFromTop(20));
    filterCutoff.setBounds(30, 100, 70, 70);
    filterRes.setBounds(100, 100, 70, 70);

}
