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
#include "TimeEditComponent.h"

using namespace rdd;

//==============================================================================
WaypointTableComponent::WaypointTableComponent() {

	// Create our table component and add it to this component..
	addAndMakeVisible(table);
	table.setModel(this);

	// give it a border
	table.setColour(ListBox::outlineColourId, Colours::grey);
	table.setOutlineThickness(1);

	table.getHeader().addColumn("Time", 1, 112, 112, 112);
	table.getHeader().addColumn("Name", 2, 300, 100, -1);

	table.getHeader().setSortColumnId(1, false);
	table.getHeader().setSortColumnId(2, false);

	table.setMultipleSelectionEnabled(false);
}


WaypointTableComponent::~WaypointTableComponent()
{
}

// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
int WaypointTableComponent::getNumRows()
{
	return MainManager::instance().getWaypointsManager().getNumWaypoints();
}

// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
void WaypointTableComponent::paintRowBackground(Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected)
{
	auto alternateColour = getLookAndFeel().findColour(ListBox::backgroundColourId)
		.interpolatedWith(getLookAndFeel().findColour(ListBox::textColourId), 0.03f);
	if (MainManager::instance().getWaypointsManager().isCheckedOut()
		&& rowNumber == (int)MainManager::instance().getWaypointsManager().getCheckedOutIdx())
	{
		g.fillAll(Colour(0xffa85c94));
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

	const Waypoint* wp = MainManager::instance().getWaypointsManager().getWaypoint((size_t)rowNumber);

	if (wp) {
		if (columnId == 1) {
			g.drawText(String(wp->t), 2, 0, width - 4, height, Justification::centredLeft, true);
		}
		else if (columnId == 2) {
			g.drawText(wp->name, 2, 0, width - 4, height, Justification::centredLeft, true);
		}


		g.setColour(getLookAndFeel().findColour(ListBox::backgroundColourId));
		g.fillRect(width - 1, 0, 1, height);

	}

}


// This is overloaded from TableListBoxModel, and must update any custom components that we're using
Component* WaypointTableComponent::refreshComponentForCell(int rowNumber, int columnId, bool /*isRowSelected*/,
	Component* existingComponentToUpdate)
{
	if (columnId == 1 || columnId == 2) // The ID and Length columns do not have a custom component
	{
		jassert(existingComponentToUpdate == nullptr);
		return nullptr;
	}

	// The other columns are editable text columns, for which we use the custom Label component
	auto* textLabel = static_cast<EditableTextCustomComponent*> (existingComponentToUpdate);

	//// same as above...
	//if (textLabel == nullptr)
	//	textLabel = new EditableTextCustomComponent(*this, MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber));
	//else
	//	textLabel->setText(MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber), NotificationType::dontSendNotification);

	//textLabel->setRowAndColumn(rowNumber, columnId);
	return textLabel;
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int WaypointTableComponent::getColumnAutoSizeWidth(int columnId)
{
	if (columnId == 1)
		return 112; // (this is the order column)
	else
		return getWidth()-112;
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

	WaypointsManager* wm = &MainManager::instance().getWaypointsManager();

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
	WaypointsManager* wm = &MainManager::instance().getWaypointsManager();

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

	table.updateContent();
	repaint();
}


//==============================================================================
void WaypointTableComponent::resized()
{
	// position our table with a gap around its edge
	table.setBoundsInset(BorderSize<int>(4));
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


