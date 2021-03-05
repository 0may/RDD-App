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
#include "RobotsManager.h"
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

	_map = MainManager::instance().getMap();
	_mapImg = _map.getMapImage();

	calculateMapArea();

	setColour(ColourIds::wpAlphaColourId, Colour(0xffa85c94));
	setColour(ColourIds::wpBetaColourId, Colour(0xff42a2c8));
	setColour(ColourIds::trailsPastColourId, Colour(0x4fa85c94));
	setColour(ColourIds::trailsFutureColourId, Colour(0x4f42a2c8));

	_wpTrails = 0;

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


	WaypointsManager *wm = &RobotsManager::instance().getSelectedRobot()->waypointsManager;

	if (wm->getNumWaypoints() == 0)  // return if list of waypoints is empty
		return;

	// compute trail start and end
	size_t wpTrailStart = 0;
	size_t wpTrailEnd = wm->getNumWaypoints()-1;

	if (wm->isCheckedOut() && _wpTrails > 0) {
		size_t coIdx = wm->getCheckedOutIdx();

		if (coIdx >= _wpTrails)
			wpTrailStart = coIdx - _wpTrails + 1;

		if (coIdx + _wpTrails - 1 < wpTrailEnd)
			wpTrailEnd = coIdx + _wpTrails - 1;
	}


	// --- draw waypoints
	g.setFillType(FillType(Colour(0x00ffffff)));
	Colour trailsColour = findColour(ColourIds::trailsPastColourId);



	// iterate over all waypoints

	set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator it = wm->cbegin();
	size_t wpIdx = 0;      // waypoint index for trails
	Point<float> p, pPrev; // screen coordinates of current and previous waypoint




	//// draw first waypoint
	//if (wpIdx >= wpTrailStart && wpIdx <= wpTrailEnd) {
	//	if (wpIdx == wm->getCheckedOutIdx()) {
	//		drawWaypoint(g, *it, true);
	//		trailsColour = findColour(ColourIds::trailsFutureColourId);
	//	}
	//	else
	//		drawWaypoint(g, *it, false);
	//}

	//pPrev = mapToScreen((*it)->x, (*it)->y);
	//it++;
	//wpIdx++;

	float animationAlpha = 1.0f;

	// draw all other waypoints and trails
	while (it != RobotsManager::instance().getSelectedRobot()->waypointsManager.cend()) {


		if (wpIdx >= wpTrailStart && wpIdx <= wpTrailEnd) {

			p = mapToScreen((*it)->x, (*it)->y);

			if (RobotsManager::instance().getSelectedRobot()->waypointsPlayer.isPlaying() && RobotsManager::instance().getSelectedRobot()->waypointsPlayer.getCurrentWaypointIdx() == wpIdx) {
				animationAlpha = 0.3f * (float)cos(RobotsManager::instance().getSelectedRobot()->waypointsPlayer.getPlayTime()*8.0) + 0.7f;
			}
			else
				animationAlpha = 1.0f;

			if (wpIdx > wpTrailStart) {

				// draw trail from current to previous waypoint
				g.setColour(trailsColour.withMultipliedAlpha(animationAlpha));
				g.drawLine(pPrev.x, pPrev.y, p.x, p.y);
			}

			// if a waypoint is selected, highlight it and change the trail color
			if (wpIdx == wm->getCheckedOutIdx()) {
				drawWaypoint(g, *it, true, animationAlpha);
				trailsColour = findColour(ColourIds::trailsFutureColourId);
			}
			else
				drawWaypoint(g, *it, false, animationAlpha);


			pPrev = p;
		}

		it++;
		wpIdx++;
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

	if (waypointHit(_mousePosition, idxMin) && idxMin == RobotsManager::instance().getSelectedRobot()->waypointsManager.getCheckedOutIdx()) {

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

	Waypoint* wpSelected = RobotsManager::instance().getSelectedRobot()->waypointsManager.getCheckedOutWaypoint();

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

	RobotsManager::instance().getSelectedRobot()->waypointsManager.commitWaypoint();


	if (e.mods.isShiftDown()) {
		Waypoint* wp = RobotsManager::instance().getSelectedRobot()->waypointsManager.checkoutWaypoint(RobotsManager::instance().getSelectedRobot()->waypointsManager.addNewWaypoint());
		Point<float> p = screenToMap(_mousePosition.x, _mousePosition.y);
		wp->x = p.x;
		wp->y = p.y;
		sendChangeMessage();
	}
	else {
		size_t idxMin = (size_t)-1;

		if (waypointHit(_mousePosition, idxMin)) {
			RobotsManager::instance().getSelectedRobot()->waypointsManager.checkoutWaypoint(idxMin);
		}
	}

    //[/UserCode_mouseDoubleClick]
}

void WaypointMapComponent::mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...

	float dy = wheel.deltaY;

	if (dy < 0 && _mapZoom > 0.7f) {

		_mapZoom /= 1.08f;

		_mapOffsetX = (_mapOffsetX - e.getPosition().x) / 1.08f + e.getPosition().x;
		_mapOffsetY = (_mapOffsetY - e.getPosition().y) / 1.08f + e.getPosition().y;


		//if (_mapZoom < 1.0f)
		//	_mapZoom = 1.0f;
	}
	else if (dy > 0 && _mapZoom < 5.0f) {
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

	_mapDisplayScaling = _mapDisplayW / (float)_mapImg.getWidth();
}




void WaypointMapComponent::drawWaypoint(juce::Graphics& g, Waypoint* wp, bool highlight, float opaqueness) {
	Point<float> a, b;
	Point<float> p = mapToScreen(wp->x, wp->y);


	if (highlight) {
		g.setColour(findColour(ColourIds::wpAlphaColourId).withMultipliedAlpha(opaqueness));
		g.drawEllipse(p.x - _wpOffL, p.y - _wpOffL, _wpSizeL, _wpSizeL, 2);

		a = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffL, true);
		b = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffL + _wpOffL2, true);
		g.drawLine(p.x + a.x, p.y + a.y, p.x + b.x, p.y + b.y, 2);


		g.setColour(findColour(ColourIds::wpBetaColourId).withMultipliedAlpha(opaqueness));
		g.drawEllipse(p.x - _wpOffL2, p.y - _wpOffL2, _wpSizeL2, _wpSizeL2, 2);

		b = Util::polarToCartesian(wp->beta * float_Pi / 180.0f, _wpOffL2, true);
		g.drawLine(p.x, p.y, p.x + b.x, p.y + b.y, 2);
	}
	else {
		g.setColour(findColour(ColourIds::wpAlphaColourId).withAlpha(0.9f).withMultipliedAlpha(opaqueness));
		g.drawEllipse(p.x - _wpOffS, p.y - _wpOffS, _wpSizeS, _wpSizeS, 1);

		a = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffS, true);
		b = Util::polarToCartesian(wp->alpha * float_Pi / 180.0f, _wpOffS + _wpOffS2, true);
		g.drawLine(p.x + a.x, p.y + a.y, p.x + b.x, p.y + b.y, 1);

		g.setColour(findColour(ColourIds::wpBetaColourId).withAlpha(0.9f).withMultipliedAlpha(opaqueness));
		g.drawEllipse(p.x - _wpOffS2, p.y - _wpOffS2, _wpSizeS2, _wpSizeS2, 1);

		b = Util::polarToCartesian(wp->beta * float_Pi / 180.0f, _wpOffS2, true);
		g.drawLine(p.x, p.y, p.x + b.x, p.y + b.y, 1);

	}
}




bool WaypointMapComponent::waypointHit(Point<int> mousePosition, size_t& wpIdx) {
	float d, dMin = 1000000.0f;
	size_t idx = 0, idxMin = (size_t)-1;

	Waypoint* wpSelected = RobotsManager::instance().getSelectedRobot()->waypointsManager.getCheckedOutWaypoint();

	if (wpSelected && waypointHitDistance(mousePosition, wpSelected) <= _wpSizeS) {
		wpIdx = RobotsManager::instance().getSelectedRobot()->waypointsManager.getCheckedOutIdx();
		return true;
	}

	for (set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator it = RobotsManager::instance().getSelectedRobot()->waypointsManager.cbegin();
		it != RobotsManager::instance().getSelectedRobot()->waypointsManager.cend();
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
		(mapX - _map.getOrigin().x) / _map.getResolution() * _mapZoom * _mapDisplayScaling + _mapOffsetX + _mapDisplayX,
		(_mapImg.getHeight() - (mapY - _map.getOrigin().y)/_map.getResolution()) * _mapZoom * _mapDisplayScaling + _mapOffsetY + _mapDisplayY
		);
}



Point<float> WaypointMapComponent::screenToMap(float screenX, float screenY) {
	//return Point<float>(
	//	(screenX - _mapOffsetX - _mapDisplayX) / (_mapZoom * _mapDisplayScaling),
	//	(screenY - _mapOffsetY - _mapDisplayY) / (_mapZoom * _mapDisplayScaling)
	//	);
	return Point<float>(
		(screenX - _mapOffsetX - _mapDisplayX) / (_mapZoom * _mapDisplayScaling) *_map.getResolution() + _map.getOrigin().x,
		(_mapImg.getHeight() - (screenY - _mapOffsetY - _mapDisplayY) / (_mapZoom * _mapDisplayScaling)) * _map.getResolution() + _map.getOrigin().y
		);
}


void WaypointMapComponent::setTrails(uint16 trails) {
	_wpTrails = trails;
}



void WaypointMapComponent::changeListenerCallback(ChangeBroadcaster* source) {
	if (dynamic_cast<WaypointsPlayer*>(source)) {
		repaint();
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
                 parentClasses="public juce::Component, public juce::ChangeBroadcaster, public juce::ChangeListener"
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

