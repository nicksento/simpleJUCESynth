/*
  ==============================================================================

    SynthSound.h
    Created: 12 Mar 2020 7:17:23pm
    Author:  Theodore

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote(int /*midiNoteNumber*/) override
    {
        return true;
    }
    
    bool appliesToChannel(int /*midiChannel*/) override
    {
        return true;
    }
};
