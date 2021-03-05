/*
  ==============================================================================

    MainMenuComponent.h
    Created: 3 Mar 2021 12:07:23pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MainManager.h"
#include "LogComponent.h"

//==============================================================================
/*
*/
class MainMenuComponent : public juce::Component,
    public juce::ApplicationCommandTarget,
    public juce::MenuBarModel
{
public:

    enum CommandIDs
    {
        quit = 1010,
        logWindow
    };


    MainMenuComponent();
    ~MainMenuComponent() override;

    void resized() override;

    StringArray getMenuBarNames() override;


    PopupMenu getMenuForIndex(int menuIndex, const String& /*menuName*/) override;

    void menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/) override {}

    ApplicationCommandTarget* getNextCommandTarget() override;

    void getAllCommands(Array<CommandID>& c) override;

    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;

    bool perform(const InvocationInfo& info) override;


    void toggleLogWindow();


private:


    std::unique_ptr<MenuBarComponent> _menuBar;
    std::unique_ptr<TextButton> _robotSelectButton;
    std::unique_ptr<TextButton> _logWindowButton;

    std::unique_ptr <DocumentWindow> _logWindow;
    LogComponent _logComponent;
    bool _showLogger;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainMenuComponent)
};