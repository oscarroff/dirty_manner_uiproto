/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2020 - Raw Material Software Limited

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             dirty_manner_ui
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Displays labels.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2019, linux_make, xcode_iphone, androidstudio

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible (titleLabel);
        titleLabel.setFont (juce::Font (16.0f, juce::Font::bold));
        titleLabel.setText ("input a date*", juce::dontSendNotification);
        titleLabel.setColour (juce::Label::textColourId, juce::Colours::lightgreen);
        titleLabel.setJustificationType (juce::Justification::centred);

        // addAndMakeVisible (inputLabel);
        // inputLabel.setText ("Date:", juce::dontSendNotification);
        // inputLabel.attachToComponent (&inputText, true);
        // inputLabel.setColour (juce::Label::textColourId, juce::Colours::orange);
        // inputLabel.setJustificationType (juce::Justification::right);

        // addAndMakeVisible (statusLabel);
        // statusLabel.setText ("Status:", juce::dontSendNotification);
        // statusLabel.attachToComponent (&statusText, true);
        // statusLabel.setColour (juce::Label::textColourId, juce::Colours::orange);
        // statusLabel.setJustificationType (juce::Justification::right);

        addAndMakeVisible (statusText);
        statusText.setColour (juce::Label::backgroundColourId, juce::Colours::black);
        inputText.setJustificationType (juce::Justification::centred);

        addAndMakeVisible (inputText);
        inputText.setText ("DD/MM/YYYY", juce::dontSendNotification);
        inputText.setEditable (true);
        inputText.setColour (juce::Label::backgroundColourId, juce::Colours::darkblue);
        inputText.onTextChange = [this] { statusText.setText (inputText.getText().toUpperCase(), juce::dontSendNotification); };
        inputText.setJustificationType (juce::Justification::centred);

        setSize (320, 200);
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }

    void resized() override
    {
        titleLabel   .setBounds (10,  10, getWidth() - 20,  30);
        inputText    .setBounds (110, 50, getWidth() - 220, 20);
        statusText.setBounds (110, 80, getWidth() - 220, 20);
    }

private:
    //==============================================================================
    juce::Label titleLabel;
    // juce::Label inputLabel;
    juce::Label inputText;
    juce::Label statusLabel;
    juce::Label statusText;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
