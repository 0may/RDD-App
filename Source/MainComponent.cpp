/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "MainManager.h"

//==============================================================================
MainComponent::MainComponent()
{
	Logger::setCurrentLogger(&_logComponent);

	setSize(1600, 900);

	// init MainManager
	rdd::MainManager::instance();

}

MainComponent::~MainComponent()
{
	Logger::setCurrentLogger(nullptr);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    //g.setFont (Font (16.0f));
    //g.setColour (Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    

	addAndMakeVisible(_tabsComponent);
	addAndMakeVisible(_logComponent);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.


	auto area = getLocalBounds();

	_logComponent.setBounds(area.removeFromBottom(200));
	_tabsComponent.setBounds(area);

    
 //   FlexBox fb;
	//fb.flexDirection = FlexBox::Direction::column;
	//fb.flexWrap = FlexBox::Wrap::noWrap;
	//fb.justifyContent = FlexBox::JustifyContent::center;
	//fb.alignContent = FlexBox::AlignContent::stretch;
	//fb.alignItems = FlexBox::AlignItems::stretch;

	//fb.items.add(FlexItem(900, 300, *_tabsComponent).withFlex(0.9f, 1.1f, 1.0f));
	//fb.items.add(FlexItem(900, 100, _logComponent));
	//
	//fb.performLayout(getLocalBounds().toFloat());
}
