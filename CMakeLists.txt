cmake_minimum_required(VERSION 3.15)

project(dirty_manner_ui VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

# Path to JUCE (adjust this!)
add_subdirectory(JUCE)

# Create the app
juce_add_gui_app(dirty_manner_ui
    PRODUCT_NAME "dirty_manner_ui"
)

# Generate header filers
juce_generate_juce_header(dirty_manner_ui)

# Add your source files
target_sources(dirty_manner_ui PRIVATE
    Source/Main.cpp
    Source/PluginEditor.cpp
    Source/WavetableFetcher.cpp
    # Source/HeaderLoader.cpp
)

# Link JUCE modules (from PIP metadata)
target_link_libraries(dirty_manner_ui PRIVATE
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    curlpp
    curl
)

# Recommended compile definitions
target_compile_definitions(dirty_manner_ui PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)
