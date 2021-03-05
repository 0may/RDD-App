/*
  ==============================================================================

    WaypointTableComponent.cpp
    Created: 9 Feb 2021 3:14:42pm
    Author:  omay

  ==============================================================================
*/

#include "WaypointTableComponent.h"

#include <JuceHeader.h>
#include "WaypointTableComponent.h"
#include "MainManager.h"
#include "RobotsManager.h"
#include "TimeEditComponent.h"
#include "WaypointEditComponent.h"

using namespace rdd;

//==============================================================================
WaypointTableComponent::WaypointTableComponent() {

	// Create our table component and add it to this component..
	addAndMakeVisible(_waypointsTable);
	_waypointsTable.setModel(this);

	// give it a border
	_waypointsTable.setColour(ListBox::outlineColourId, Colours::grey);
	_waypointsTable.setOutlineThickness(1);

	_waypointsTable.getHeader().addColumn("Time", 1, 100, 100, 100);
	_waypointsTable.getHeader().addColumn("Name", 2, 198, 30, -1);

	_waypointsTable.getHeader().setSortColumnId(1, false);
	_waypointsTable.getHeader().setSortColumnId(2, false);

	_waypointsTable.setMultipleSelectionEnabled(false);
}


WaypointTableComponent::~WaypointTableComponent()
{
}

// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
int WaypointTableComponent::getNumRows()
{
	return RobotsManager::instance().getSelectedRobot()->waypointsManager.getNumWaypoints();
}

// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
void WaypointTableComponent::paintRowBackground(Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected)
{
	auto alternateColour = getLookAndFeel().findColour(ListBox::backgroundColourId)
		.interpolatedWith(getLookAndFeel().findColour(ListBox::textColourId), 0.03f);
	if (RobotsManager::instance().getSelectedRobot()->waypointsManager.isCheckedOut()
		&& rowNumber == (int)RobotsManager::instance().getSelectedRobot()->waypointsManager.getCheckedOutIdx())
	{
		g.fillAll(Colour(0xffa45c94));
	}
	else if (rowNumber % 2)
		g.fillAll(alternateColour);

}

// This is overloaded from TableListBoxModel, and must paint any cells that aren't using custom
// components.
void WaypointTableComponent::paintCell(Graphics& g, int rowNumber, int columnId,
	int width, int height, bool /*rowIsSelected*/)
{
	g.setColour(getLookAndFeel().findColour(ListBox::textColourId));
	g.setFont(font);

	const Waypoint* wp = RobotsManager::instance().getSelectedRobot()->waypointsManager.getWaypoint((size_t)rowNumber);

	if (wp) {
		if (columnId == 1) {
			g.drawText(rdd::Time(wp->t).toString(), 2, 0, width - 8, height, Justification::centredRight, true);
		}
		else if (columnId == 2) {
			g.drawText(wp->name, 4, 0, width - 6, height, Justification::centredLeft, true);
		}


		g.setColour(getLookAndFeel().findColour(ListBox::backgroundColourId));
		g.fillRect(width - 1, 0, 1, height);

	}

}


// This is overloaded from TableListBoxModel, and must update any custom components that we're using
Component* WaypointTableComponent::refreshComponentForCell(int rowNumber, int columnId, bool /*isRowSelected*/,
	Component* existingComponentToUpdate)
{
	//if (columnId == 1 || columnId == 2) // The ID and Length columns do not have a custom component
	//{
		jassert(existingComponentToUpdate == nullptr);
		return nullptr;
//	}

	// The other columns are editable text columns, for which we use the custom Label component
	//auto* textLabel = static_cast<EditableTextCustomComponent*> (existingComponentToUpdate);

	//// same as above...
	//if (textLabel == nullptr)
	//	textLabel = new EditableTextCustomComponent(*this, MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber));
	//else
	//	textLabel->setText(MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber), NotificationType::dontSendNotification);

	//textLabel->setRowAndColumn(rowNumber, columnId);
	//return textLabel;
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int WaypointTableComponent::getColumnAutoSizeWidth(int columnId)
{
	if (columnId == 1)
		return 90; // (this is the order column)
	else
		return getWidth()-90;
}


void WaypointTableComponent::selectedRowsChanged(int lastRowSelected) {
	//if (lastRowSelected == MainManager::instance().midiSequenceManager().getSelectedMidiSequenceIdx()) {
	//	MainManager::instance().midiSequenceManager().unselectMidiSequence();

	//	String s("unselecting ");
	//	s << lastRowSelected;

	//	Logger::writeToLog(s);
	//}
	//else {
	//	MainManager::instance().midiSequenceManager().selectMidiSequence(lastRowSelected);

	//	String s("selecting ");
	//	s << lastRowSelected;
	//	Logger::writeToLog(s);
	//}
}


void WaypointTableComponent::cellClicked(int rowNumber, int columnId, const MouseEvent&) {

	WaypointsManager* wm = &RobotsManager::instance().getSelectedRobot()->waypointsManager;

	if (rowNumber == (int)wm->getCheckedOutIdx()) {
		wm->commitWaypoint();
	}
	else {
		if (wm->isCheckedOut())
			wm->commitWaypoint();
		wm->checkoutWaypoint((size_t)rowNumber);
	}

	repaint();

}


void WaypointTableComponent::backgroundClicked(const MouseEvent&) {
	WaypointsManager* wm = &RobotsManager::instance().getSelectedRobot()->waypointsManager;

	if (wm->isCheckedOut())
		wm->commitWaypoint();

	repaint();
}


String WaypointTableComponent::getText(const int columnNumber, const int rowNumber) const
{
	//if (columnNumber == 2) {
	//	return MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber);
	//}
	//else if (columnNumber == 1)
	//	return String(rowNumber + 1);
	//else
		return String("whoaat");
}

void WaypointTableComponent::setText(const int columnNumber, const int rowNumber, const String& newText)
{
	//if (columnNumber == 2 && newText.isNotEmpty()) {
	//	MainManager::instance().getMidiSequenceManager().setMidiSequenceName(rowNumber, newText);
	//}
}




void WaypointTableComponent::updateTable() {

	_waypointsTable.updateContent();
	repaint();
}


//==============================================================================
void WaypointTableComponent::resized()
{
	// position our table with a gap around its edge
	//table.setBoundsInset(BorderSize<int>(4));
	_waypointsTable.setBounds(getLocalBounds());
}



//void WaypointTableComponent::paint (juce::Graphics& g)
//{
//    /* This demo code just fills the component's background and
//       draws some placeholder text to get you started.
//
//       You should replace everything in this method with your own
//       drawing code..
//    */
//
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
//
//    g.setColour (juce::Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (juce::Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("WaypointTableComponent", getLocalBounds(),
//                juce::Justification::centred, true);   // draw some placeholder text
//}


