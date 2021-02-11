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
#include "WaypointEditComponent.h"
#include "Util.h"
#include <math.h>
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
	_wpSizeL = 31.0f;
	_wpSizeS = 21.0f;

	_wpOffL = (float)(_wpSizeL * 0.5f);
	_wpSizeL2 = _wpSizeL * 0.666f;
	_wpOffL2 = (float)(_wpSizeL2 * 0.5f);

	_wpOffS = (float)(_wpSizeS * 0.5f);
	_wpSizeS2 = _wpSizeS * 0.666f;
	_wpOffS2 = (float)(_wpSizeS2 * 0.5f);

	_wpMove = false;
	_wpRotateA = false;
	_wpRotateB = false;


	//File mapImageFile(rdd::MainManager::instance().getAssetsDirectory().getChildFile("map/map.png"));
	//_mapImg = PNGImageFormat::loadFrom(mapImageFile);

	_mapImg = MainManager::instance().getMap().getMapImage();

	calculateMapArea();

	setColour(ColourIds::wpAlphaColourId, Colour(0xffa85c94));
	setColour(ColourIds::wpBetaColourId, Colour(0xff42a2c8));
	setColour(ColourIds::trailsPastColourId, Colour(0x4fa85c94));
	setColour(ColourIds::trailsFutureColourId, Colour(0x4f42a2c8));

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


	// --- draw map image with current zoom and offset
	g.drawImageWithin(
		_mapImg,
		(int)(_mapDisplayX + _mapOffsetX),
		(int)(_mapDisplayY + _mapOffsetY),
		(int)(_mapDisplayW * _mapZoom),
		(int)(_mapDisplayH * _mapZoom),
		RectanglePlacement(64)
	);


	// --- draw waypoints

	g.setFillType(FillType(Colour(0x00ffffff)));
	Colour trailsColour = findColour(ColourIds::trailsPastColourId);

	Waypoint* wpSelected = MainManager::instance().getWaypointsManager().getCheckedOutWaypoint();
	Point<float> p, pPrev;

	// iterate over all waypoints

	set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator it = MainManager::instance().getWaypointsManager().cbegin();

	if (it != MainManager::instance().getWaypointsManager().cend()) {  // if list of waypoints is not empty

		// draw first waypoint
		if (wpSelected && wpSelected == *it) {
			drawWaypoint(g, *it, true);
			trailsColour = findColour(ColourIds::trailsFutureColourId);
		}
		else
			drawWaypoint(g, *it, false);

		pPrev = mapToScreen((*it)->x, (*it)->y);
		it++;

		// draw all other waypoints and trails 
		while (it != MainManager::instance().getWaypointsManager().cend()) {

			// draw trail from current to previous waypoint
			p = mapToScreen((*it)->x, (*it)->y);
			g.setColour(trailsColour);
			g.drawLine(pPrev.x, pPrev.y, p.x, p.y);

			// if a waypoint is selected, highlight it and change the trail color
			if (wpSelected && wpSelected == *it) {
				drawWaypoint(g, *it, true);
				trailsColour = findColour(ColourIds::trailsFutureColourId);
			}
			else
				drawWaypoint(g, *it, false);

			pPrev = p;
			it++;
		}
	}



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


	size_t idxMin = (size_t)-1;

	if (waypointHit(_mousePosition, idxMin) && idxMin == MainManager::instance().getWaypointsManager().getCheckedOutIdx()) {

		if (e.mods.isCtrlDown()) {
			_wpRotateA = true;
		}
		else if (e.mods.isAltDown()) {
			_wpRotateB = true;
		}
		else if (!e.mods.isShiftDown()) {
			_wpMove = true;
		}
	}


    //[/UserCode_mouseDown]
}

void WaypointMapComponent::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	auto pos = e.getPosition();

	Waypoint* wpSelected = MainManager::instance().getWaypointsManager().getCheckedOutWaypoint();

	if (wpSelected && _wpMove) {
		// move selected waypoint
		Point<float> d = screenToMap((float)pos.x, (float)pos.y) - screenToMap((float)_mousePosition.x, (float)_mousePosition.y);
		wpSelected->x += d.x;
		wpSelected->y += d.y;
		sendChangeMessage();
	}
	else if (wpSelected && _wpRotateA) {
		// rotate alpha
		if (e.mods.isShiftDown())
			wpSelected->alpha -= 0.2f*(pos.y - (float)_mousePosition.y);
		else
			wpSelected->alpha -= pos.y - (float)_mousePosition.y;

		sendChangeMessage();
	}
	else if (wpSelected && _wpRotateB) {
		// rotate beta
		if (e.mods.isShiftDown())
			wpSelected->beta -= 0.2f * (pos.y - (float)_mousePosition.y);
		else
			wpSelected->beta -= pos.y - (float)_mousePosition.y;

		sendChangeMessage();
	}
	else if(e.mods.isShiftDown()) {
		// move map
		_mapOffsetX += pos.x - (float)_mousePosition.x;
		_mapOffsetY += pos.y - (float)_mousePosition.y;
	}


	_mousePosition = pos;

	repaint();

    //[/UserCode_mouseDrag]
}

void WaypointMapComponent::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
	_wpMove = false;
	_wpRotateA = false;
	_wpRotateB = false;


    //[/UserCode_mouseUp]
}

void WaypointMapComponent::mouseDoubleClick (const juce::MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...

	_mousePosition = e.getPosition();

	MainManager::instance().getWaypointsManager().commitWaypoint();

	size_t idxMin = (size_t)-1;

	if (waypointHit(_mousePosition, idxMin)) {
		MainManager::instance().getWaypointsManager().checkoutWaypoint(idxMin);
	}

    //[/UserCode_mouseDoubleClick]
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




void WaypointMapComponent::drawWaypoint(juce::Graphics& g, Waypoint* wp, bool highlight) {
	Point<float> a, b;
	Point<float> p = mapToScreen(wp->x, wp->y);


	if (highlight) {
		g.setColour(findColour(ColourIds::wpAlphaColourId));
		g.drawEllipse(p.x - _wpOffL, p.y - _wpOffL, _wpSizeL, _wpSizeL, 2);

		a = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffL, true);
		b = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffL + _wpOffL2, true);
		g.drawLine(p.x + a.x, p.y + a.y, p.x + b.x, p.y + b.y, 2);


		g.setColour(findColour(ColourIds::wpBetaColourId));
		g.drawEllipse(p.x - _wpOffL2, p.y - _wpOffL2, _wpSizeL2, _wpSizeL2, 2);

		b = Util::polarToCartesian(wp->beta * float_Pi / 180.0f, _wpOffL2, true);
		g.drawLine(p.x, p.y, p.x + b.x, p.y + b.y, 2);
	}
	else {
		g.setColour(findColour(ColourIds::wpAlphaColourId).withAlpha(0.9f));
		g.drawEllipse(p.x - _wpOffS, p.y - _wpOffS, _wpSizeS, _wpSizeS, 1);

		a = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffS, true);
		b = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffS + _wpOffS2, true);
		g.drawLine(p.x + a.x, p.y + a.y, p.x + b.x, p.y + b.y, 1);

		g.setColour(findColour(ColourIds::wpBetaColourId).withAlpha(0.9f));
		g.drawEllipse(p.x - _wpOffS2, p.y - _wpOffS2, _wpSizeS2, _wpSizeS2, 1);

		b = Util::polarToCartesian(wp->beta * float_Pi / 180.0f, _wpOffS2, true);
		g.drawLine(p.x, p.y, p.x + b.x, p.y + b.y, 1);

	}
}




bool WaypointMapComponent::waypointHit(Point<int> mousePosition, size_t& wpIdx) {
	float d, dMin = 1000000.0f;
	size_t idx = 0, idxMin = (size_t)-1;

	Waypoint* wpSelected = MainManager::instance().getWaypointsManager().getCheckedOutWaypoint();

	if (wpSelected && waypointHitDistance(mousePosition, wpSelected) <= _wpSizeS) {
		wpIdx = MainManager::instance().getWaypointsManager().getCheckedOutIdx();
		return true;
	}

	for (set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator it = MainManager::instance().getWaypointsManager().cbegin();
		it != MainManager::instance().getWaypointsManager().cend();
		it++)
	{
		d = waypointHitDistance(mousePosition, *it);

		if (d < dMin) {
			dMin = d;
			idxMin = idx;
		}

		idx++;
	}

	if (dMin <= _wpSizeS) {
		wpIdx = idxMin;
		return true;
	}
	else {
		return false;
	}
}



Point<float> WaypointMapComponent::mapToScreen(float mapX, float mapY) {
	return Point<float>(
		mapX * _mapZoom + _mapOffsetX + _mapDisplayX,
		mapY * _mapZoom + _mapOffsetY + _mapDisplayY
		);
}



Point<float> WaypointMapComponent::screenToMap(float screenX, float screenY) {
	return Point<float>(
		(screenX - _mapOffsetX - _mapDisplayX) / _mapZoom,
		(screenY - _mapOffsetY - _mapDisplayY) / _mapZoom
		);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointMapComponent" componentName=""
                 parentClasses="public juce::Component, public juce::ChangeBroadcaster"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <METHODS>
    <METHOD name="mouseWheelMove (const juce::MouseEvent&amp; e, const juce::MouseWheelDetails&amp; wheel)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDoubleClick (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff412f49"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

