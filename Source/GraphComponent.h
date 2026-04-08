#pragma once

//==============================================================================
class GraphComponent : public juce::Component
{
public:
    GraphComponent() : data(nullptr), dataSize(0) {}
    
    // Set the data to display
    void setData(const float* dataPtr, int size)
    {
        data = dataPtr;
        dataSize = size;
        repaint();
    }
    
    void paint(juce::Graphics& g) override
    {
        // Draw background
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::darkgrey);
        g.drawRect(getLocalBounds(), 1);
        
        if (data == nullptr || dataSize <= 1)
            return;
        
        // Find min and max values for scaling
        float minVal = data[0];
        float maxVal = data[0];
        for (int i = 0; i < dataSize; ++i)
        {
            minVal = juce::jmin(minVal, data[i]);
            maxVal = juce::jmax(maxVal, data[i]);
        }
        
        // Prevent division by zero
        if (maxVal == minVal)
            maxVal = minVal + 1.0f;
        
        float range = maxVal - minVal;
        float width = (float)getWidth();
        float height = (float)getHeight();
        int padding = 10;
        float graphWidth = width - 2 * padding;
        float graphHeight = height - 2 * padding;
        
        // Draw graph line
        g.setColour(juce::Colours::green);
        for (int i = 0; i < dataSize - 1; ++i)
        {
            float x1 = padding + (i / (float)(dataSize - 1)) * graphWidth;
            float y1 = height - padding - ((data[i] - minVal) / range) * graphHeight;
            
            float x2 = padding + ((i + 1) / (float)(dataSize - 1)) * graphWidth;
            float y2 = height - padding - ((data[i + 1] - minVal) / range) * graphHeight;
            
            g.drawLine(x1, y1, x2, y2, 2.0f);
        }
        
        // Draw points
        g.setColour(juce::Colours::yellow);
        for (int i = 0; i < dataSize; ++i)
        {
            float x = padding + (i / (float)(dataSize - 1)) * graphWidth;
            float y = height - padding - ((data[i] - minVal) / range) * graphHeight;
            g.fillEllipse(x - 3, y - 3, 6, 6);
        }
        
        // Draw axes
        g.setColour(juce::Colours::white);
        g.drawLine(padding, height - padding, width - padding, height - padding, 1.0f); // X-axis
        g.drawLine(padding, padding, padding, height - padding, 1.0f); // Y-axis
    }
    
private:
    const float* data;
    int dataSize;
};
