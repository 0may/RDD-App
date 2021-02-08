/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "MainManager.h"
//[/Headers]

#include "WaypointMapComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaypointMapComponent::WaypointMapComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	_mapZoom = 1.0f;
	_mapOffsetX = 0.0f;
	_mapOffsetY = 0.0f;
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..


	File mapImageFile(rdd::MainManager::instance().getAssetsDirectory().getChildFile("Maps/map.png"));


	_mapImg = PNGImageFormat::loadFrom(mapImageFile);

	calculateMapArea();

    //[/Constructor]
}

WaypointMapComponent::~WaypointMapComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaypointMapComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff412f49));

    //[UserPaint] Add your own custom painting code here..

	//g.drawImageWithin(
	//	_mapImg,
	//	_mapOffsetX, // + (1.0f - _mapZoom)*getLocalBounds().getWidth(),
	//	_mapOffsetY, // + (1.0f - _mapZoom)*getLocalBounds().getHeight(),
	//	getLocalBounds().getWidth()*_mapZoom,
	//	getLocalBounds().getHeight()*_mapZoom,
	//	RectanglePlacement(4 + 32)
	//);

	g.drawImageWithin(
		_mapImg,
		_mapDisplayX + _mapOffsetX,
		_mapDisplayY + _mapOffsetY,
		_mapDisplayW * _mapZoom,
		_mapDisplayH * _mapZoom,
		RectanglePlacement(64)
	);
    //[/UserPaint]
}

void WaypointMapComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	calculateMapArea();
    //[/UserResized]
}

void WaypointMapComponent::mouseDown (const juce::MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	_mousePosition = e.getPosition();
    //[/UserCode_mouseDown]
}

void WaypointMapComponent::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	auto pos = e.getPosition();

	_mapOffsetX += pos.x - _mousePosition.x;
	_mapOffsetY += pos.y - _mousePosition.y;

	_mousePosition = pos;

	repaint();

    //[/UserCode_mouseDrag]
}

void WaypointMapComponent::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    //[/UserCode_mouseUp]
}

void WaypointMapComponent::mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...

	float dy = wheel.deltaY;

	if (dy > 0 && _mapZoom > 1.0f) {
		_mapZoom /= 1.08f;

		_mapOffsetX = (_mapOffsetX - e.getPosition().x) / 1.08f + e.getPosition().x;
		_mapOffsetY = (_mapOffsetY - e.getPosition().y) / 1.08f + e.getPosition().y;


		if (_mapZoom < 1.0f)
			_mapZoom = 1.0f;
	}
	else if (dy < 0 && _mapZoom < 4.0f) {
		_mapZoom *= 1.08f;

		_mapOffsetX = (_mapOffsetX - e.getPosition().x) * 1.08f + e.getPosition().x;
		_mapOffsetY = (_mapOffsetY - e.getPosition().y) * 1.08f + e.getPosition().y;

	}



	repaint();

	//Logger::writeToLog(String(dy) + "    zoom: " + String(_mapZoom));

    //[/UserCode_mouseWheelMove]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void WaypointMapComponent::calculateMapArea() {

	float mapW = (float)_mapImg.getWidth();
	float mapH = (float)_mapImg.getHeight();
	float viewportW = (float)getLocalBounds().getWidth();
	float viewportH = (float)getLocalBounds().getHeight();

	if (viewportW/viewportH < mapW/mapH) {
		_mapDisplayW = viewportW;
		_mapDisplayH = mapH * _mapDisplayW / mapW;
		_mapDisplayX = 0.0f;
		_mapDisplayY = (viewportH - _mapDisplayH)*0.5f;
	}
	else {
		_mapDisplayH = viewportH;
		_mapDisplayW = mapW * _mapDisplayH / mapH;
		_mapDisplayY = 0.0f;
		_mapDisplayX = (viewportW - _mapDisplayW)*0.5f;
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointMapComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseWheelMove (const juce::MouseEvent&amp; e, const juce::MouseWheelDetails&amp; wheel)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff412f49"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

