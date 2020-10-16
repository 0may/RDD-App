/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "XYInputComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
XYInputComponent::XYInputComponent (int width, int height, String identifier)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (511, 511);


    //[Constructor] You can add your own custom stuff here..
	setSize(width, height);

	setMapping(-1, 1, -1, 1);

	_mouseDown = false;
	_mouseInput.x = (int)(width*0.5);    // remember the 1 pixel sized border
	_mouseInput.y = (int)(height*0.5);
	_mouseInputPrevious = _mouseInput;
	_inputDims = XY;

	_identifier = identifier;


	setColour(ColourIds::indicatorColourId, Colour(0xffa45c94));
	setColour(ColourIds::backgroundColourId, Colour(0xff121e24));
	setColour(ColourIds::borderColourId, Colour(0xffafafaf));


	/*
	_bgColor = Colour(0xff121e24);
	_borderColor = Colour(0xffafafaf);*/

    //[/Constructor]
}

XYInputComponent::~XYInputComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void XYInputComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..

	int cx = (int)(getWidth()*0.5);   // center in x-dim (in pixels)
	int cy = (int)(getHeight()*0.5);  // center in y-dim (in pixels)

    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff121e24));

    //[UserPaint] Add your own custom painting code here..


	g.fillAll(findColour(ColourIds::backgroundColourId));

	g.setColour(findColour(ColourIds::borderColourId));

	if (_inputDims == XY) {
		// draw quadrant separators
		g.drawLine(0.0f, (float)cy, getWidth() - 1.0f, (float)cy, 1.0f);
		g.drawLine((float)cx, 0.0f, (float)cx, getHeight() - 1.0f, 1.0f);

		// draw center
		//g.setColour(Colours::white);
		//g.fillEllipse(cx - 1, cy - 1, 3, 3);

		if (_mouseDown) {

			// draw indicator arrow
			g.setColour(findColour(ColourIds::indicatorColourId));
			g.drawArrow(Line<float>((float)cx, (float)cy, (float)_mouseInput.x, (float)_mouseInput.y), 11.0f, 11.0f, 11.0f);
		}
	}
	else if (_inputDims == X) {
		// draw center
		g.drawLine((float)cx, 0.0f, (float)cx, getHeight() - 1.0f, 1.0f);

		if (_mouseDown) {

			// draw indicator bar
			g.setColour(findColour(ColourIds::indicatorColourId));

			if (cx < _mouseInput.x)
				g.fillRect(cx+1, 1, _mouseInput.x - cx, getHeight() - 2);
			else
				g.fillRect(_mouseInput.x, 1, cx - _mouseInput.x, getHeight() - 2);
		}
	}
	else {
		// draw center
		g.drawLine(0.0f, (float)cy, getWidth() - 1.0f, (float)cy, 1.0f);

		if (_mouseDown) {

			// draw indicator bar
			g.setColour(findColour(ColourIds::indicatorColourId));

			if (cy < _mouseInput.y)
				g.fillRect(1, cy+1, getWidth() - 2, _mouseInput.y - cy);
			else
				g.fillRect(1, _mouseInput.y, getWidth() - 2, cy - _mouseInput.y);
		}
	}

	// draw border
	g.setColour(findColour(ColourIds::borderColourId));
	g.drawRect(0, 0, getWidth(), getHeight(), 1);

    //[/UserPaint]
}

void XYInputComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void XYInputComponent::setMapping(float xLeft, float xRight, float yTop, float yBottom) {

	jassert(!(xLeft == xRight && yTop == yBottom));

	_mapX[0] = xLeft;
	_mapX[1] = xRight;
	_mapY[0] = yTop;
	_mapY[1] = yBottom;

	if (xLeft == xRight)
		_inputDims = Y;
	else if (yTop == yBottom)
		_inputDims = X;
	else
		_inputDims = XY;
}


bool XYInputComponent::hasInput() const {
	return _mouseDown;
}


const Point<int>& XYInputComponent::getInput() const {
	return _mouseInput;
}


Point<float> XYInputComponent::getMappedInput() const {
	return Point<float>((_mouseInput.x - 1) / (float)(getWidth() - 2) * (_mapX[1] - _mapX[0]) + _mapX[0], (_mouseInput.y - 1) / (float)(getHeight() - 2) * (_mapY[1] - _mapY[0]) + _mapY[0]);
}


const Point<int>& XYInputComponent::getInputPrevious() const {
	return _mouseInputPrevious;
}


Point<float> XYInputComponent::getMappedInputPrevious() const {
	return Point<float>((_mouseInputPrevious.x - 1) / (float)(getWidth() - 2) * (_mapX[1] - _mapX[0]) + _mapX[0], (_mouseInputPrevious.y - 1) / (float)(getHeight() - 2) * (_mapY[1] - _mapY[0]) + _mapY[0]);
}


const String& XYInputComponent::getIdentifier() const {
	return _identifier;
}


void XYInputComponent::mouseDown(const MouseEvent& event) {

	_mouseDown = true;

	if (_inputDims == Y)
		_mouseInput.y = event.getMouseDownPosition().y;
	else if (_inputDims == X)
		_mouseInput.x = event.getMouseDownPosition().x;
	else
		_mouseInput = event.getMouseDownPosition();

	if (_mouseInput.x < 1)
		_mouseInput.x = 1;
	else if (_mouseInput.x > getWidth() - 2)
		_mouseInput.x = getWidth() - 2;

	if (_mouseInput.y < 1)
		_mouseInput.y = 1;
	else if (_mouseInput.y > getHeight() - 2)
		_mouseInput.y = getHeight() - 2;

	_mouseInputPrevious = _mouseInput;

	//char msg[64];
	//sprintf(msg, "mousedown (%d, %d)", _mouseInput.x, _mouseInput.y);
	//Logger::writeToLog(msg);

	repaint();

	sendChangeMessage();

}


void XYInputComponent::mouseDrag(const MouseEvent& event) {


	_mouseInputPrevious = _mouseInput;

	if (_inputDims == Y)
		_mouseInput.y = event.getMouseDownPosition().y + event.getOffsetFromDragStart().y;
	else if (_inputDims == X)
		_mouseInput.x = event.getMouseDownPosition().x + event.getOffsetFromDragStart().x;
	else
		_mouseInput = event.getMouseDownPosition() + event.getOffsetFromDragStart();

	if (_mouseInput.x < 1)
		_mouseInput.x = 1;
	else if (_mouseInput.x > getWidth() - 2)
		_mouseInput.x = getWidth() - 2;

	if (_mouseInput.y < 1)
		_mouseInput.y = 1;
	else if (_mouseInput.y > getHeight() - 2)
		_mouseInput.y = getHeight() - 2;



	//char msg[64];
	//sprintf(msg, "mousedrag (%d, %d)", _mouseInput.x, _mouseInput.y);
	//Logger::writeToLog(msg);

	repaint();


	sendChangeMessage();
}


void XYInputComponent::mouseUp(const MouseEvent& /*event*/) {


	_mouseInputPrevious = _mouseInput;

	_mouseDown = false;

	//char msg[64];
	//sprintf(msg, "mouseup");
	//Logger::writeToLog(msg);

	repaint();


	sendChangeMessage();
}



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="XYInputComponent" componentName=""
                 parentClasses="public Component, public ChangeBroadcaster" constructorParams="int width, int height, String identifier"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="511" initialHeight="511">
  <BACKGROUND backgroundColour="ff121e24"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

