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

#include "GraphComponent.h"

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

        addAndMakeVisible (statusText);
        statusText.setColour (juce::Label::backgroundColourId, juce::Colours::black);
        inputText.setJustificationType (juce::Justification::centred);

        addAndMakeVisible (inputText);
        inputText.setText ("DD/MM/YYYY", juce::dontSendNotification);
        inputText.setEditable (true);
        inputText.setColour (juce::Label::backgroundColourId, juce::Colours::darkblue);
        inputText.onTextChange = [this] { statusText.setText (inputText.getText().toUpperCase(), juce::dontSendNotification); };
        inputText.setJustificationType (juce::Justification::centred);

        addAndMakeVisible (infoText);
        infoText.setFont (juce::Font (12.0f));
        infoText.setText ("PM2.5 air quality: 1 week at 1 hour intervals", juce::dontSendNotification);
        infoText.setColour (juce::Label::textColourId, juce::Colours::lightgreen);
        infoText.setJustificationType (juce::Justification::centred);

        addAndMakeVisible(graphComponent);
        
        // Example data - replace with your actual data
        exampleData = { 0.0f };
        graphComponent.setData(exampleData.data(), exampleData.size());

        setSize (320, 280);
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

        // Graph takes up the remaining space below
        graphComponent.setBounds(10, 95, getWidth() - 20, getHeight() - 120);
        infoText   .setBounds (10,  getHeight() - 30, getWidth() - 20,  20);
    }

    // Public method to indicate bad input
    void updateStatusText(const std::string status)
    {
        this->statusText.setText(status, juce::dontSendNotification);
    }
    // Public method to update graph data
    void updateGraphData(const std::vector<float>& newData)
    {
        exampleData = newData;
        graphComponent.setData(exampleData.data(), exampleData.size());
    }

private:
    //==============================================================================
    juce::Label titleLabel;
    juce::Label inputText;
    juce::Label statusText;
    juce::Label infoText;
    GraphComponent graphComponent;
    std::vector<float> exampleData;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
