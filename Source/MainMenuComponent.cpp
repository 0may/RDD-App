/*
  ==============================================================================

    MainMenuComponent.cpp
    Created: 3 Mar 2021 12:07:23pm
    Author:  omay

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainMenuComponent.h"
#include "MainManager.h"
#include "RobotsManager.h"

//==============================================================================
MainMenuComponent::MainMenuComponent()
{

    _menuBar.reset(new MenuBarComponent(this));
    addAndMakeVisible(_menuBar.get());
    
    
    _robotSelectButton.reset(new TextButton("Robot select button", "Click to select the next robot"));
    _robotSelectButton->setButtonText("Robot 1");
    _robotSelectButton->onClick = [this]() { 
        RobotsManager::instance().select((RobotsManager::instance().getSelectedIdx() + 1) % RobotsManager::instance().numRobots());
        _robotSelectButton->setButtonText("Robot " + String(RobotsManager::instance().getSelectedIdx() + 1)); 
    };
    addAndMakeVisible(_robotSelectButton.get());
    
    _logWindowButton.reset(new TextButton("Log window button", "Click to toggle log window"));
    _logWindowButton->setButtonText("Log Window");
    _logWindowButton->onClick = [this]() {
        toggleLogWindow();
    };
    addAndMakeVisible(_logWindowButton.get());



    
    setApplicationCommandManagerToWatch(&MainManager::instance().getCommandManager());
    MainManager::instance().getCommandManager().registerAllCommandsForTarget(this);

    // this lets the command manager use keypresses that arrive in our window to send out commands
    addKeyListener(MainManager::instance().getCommandManager().getKeyMappings());

    _showLogger = false;

    //toggleLogWindow();

    setSize(500, 500);
}

MainMenuComponent::~MainMenuComponent()
{
    removeKeyListener(rdd::MainManager::instance().getCommandManager().getKeyMappings());
    _logWindow = nullptr;
    _menuBar = nullptr;
}



void MainMenuComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    auto b = getLocalBounds().removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight());

    _robotSelectButton->setBounds(b.removeFromRight(100));
    _logWindowButton->setBounds(b.removeFromRight(100));
    _menuBar->setBounds(b);

}

StringArray MainMenuComponent::getMenuBarNames() {
    return { "File", "Tools" };
}


PopupMenu MainMenuComponent::getMenuForIndex(int menuIndex, const String& /*menuName*/) 
{
    PopupMenu menu;

    if (menuIndex == 0)
    {
        menu.addCommandItem(&MainManager::instance().getCommandManager(), CommandIDs::quit);
    }
    else if (menuIndex == 1)
    {
        menu.addCommandItem(&MainManager::instance().getCommandManager(), CommandIDs::logWindow);
    }

    return menu;
}

ApplicationCommandTarget* MainMenuComponent::getNextCommandTarget() 
{
    return nullptr;
}

void MainMenuComponent::getAllCommands(Array<CommandID>& c) 
{
    Array<CommandID> commands{ 
                                CommandIDs::quit, 
                                CommandIDs::logWindow 
                            };
    c.addArray(commands);
}

void MainMenuComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) 
{
    switch (commandID)
    {
    case CommandIDs::quit:
        result.setInfo("Quit", "Quit the application", "Menu", 0);
        result.setTicked(false);
        result.addDefaultKeypress('q', ModifierKeys::ctrlModifier);
        break;
    case CommandIDs::logWindow:
        result.setInfo("Log Window", "Toggles the log window", "Menu", 0);
        result.setTicked(_showLogger);
        result.setActive(true);
        result.addDefaultKeypress('l', ModifierKeys::noModifiers);
        break;
    default:
        break;
    }
}

bool MainMenuComponent::perform(const InvocationInfo& info) 
{
    switch (info.commandID)
    {
    case CommandIDs::quit:
        JUCEApplication::getInstance()->systemRequestedQuit();
        break;
    case CommandIDs::logWindow:
        toggleLogWindow();
        break;
    default:
        return false;
    }

    return true;
}



void MainMenuComponent::toggleLogWindow() {

    _showLogger = !_showLogger;

    if (_showLogger) {

        Logger::setCurrentLogger(&_logComponent);
        MainManager::instance().getMidiController().enableLogging(true);

        _logWindow.reset(new DocumentWindow("Log", Colour(0x000000), DocumentWindow::minimiseButton + DocumentWindow::maximiseButton));
        _logWindow->setContentNonOwned(&_logComponent, false);
       

        Rectangle<int> area(0, 0, 300, 600);

        RectanglePlacement placement(RectanglePlacement::xLeft
            | RectanglePlacement::yTop
            | RectanglePlacement::doNotResize);

        auto result = placement.appliedTo(area, Desktop::getInstance().getDisplays()
            .getPrimaryDisplay()->userArea.reduced(20).removeFromRight(300));
        _logWindow->setBounds(result);

        _logWindow->setResizable(true, false);
        _logWindow->setUsingNativeTitleBar(false);
        _logWindow->setVisible(true);
    }
    else {
        Logger::setCurrentLogger(nullptr);
        MainManager::instance().getMidiController().enableLogging(false);
        _logWindow = nullptr;
    }

}