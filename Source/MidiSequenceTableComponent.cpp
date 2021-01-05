/*
  ==============================================================================

    MidiSequenceTableComponent.cpp
    Created: 9 Oct 2020 8:41:10pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MidiSequenceTableComponent.h"
#include "MainManager.h"

//==============================================================================
MidiSequenceTableComponent::MidiSequenceTableComponent() {

	// Create our table component and add it to this component..
	addAndMakeVisible(table);
	table.setModel(this);

	// give it a border
	table.setColour(ListBox::outlineColourId, Colours::grey);
	table.setOutlineThickness(1);

	table.getHeader().addColumn("Order", 1, 60, 60, 60);
	table.getHeader().addColumn("Name", 2, 300, 100, -1);
	table.getHeader().addColumn("Lenght", 3, 60, 60, 60);

	table.getHeader().setSortColumnId(1, false);
	table.getHeader().setSortColumnId(2, false);
	table.getHeader().setSortColumnId(3, false);

	table.setMultipleSelectionEnabled(false);
}


MidiSequenceTableComponent::~MidiSequenceTableComponent()
{
}

// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
int MidiSequenceTableComponent::getNumRows()  
{
	return rdd::MainManager::instance().getMidiSequenceManager().getNumMidiSequences();
}

// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
void MidiSequenceTableComponent::paintRowBackground(Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected) 
{
	auto alternateColour = getLookAndFeel().findColour(ListBox::backgroundColourId)
		.interpolatedWith(getLookAndFeel().findColour(ListBox::textColourId), 0.03f);
	if (rowNumber == rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceIdx())
		g.fillAll(Colour(0xffa85c94));
	else if (rowNumber % 2)
		g.fillAll(alternateColour);

}

// This is overloaded from TableListBoxModel, and must paint any cells that aren't using custom
// components.
void MidiSequenceTableComponent::paintCell(Graphics& g, int rowNumber, int columnId,
	int width, int height, bool /*rowIsSelected*/) 
{
	g.setColour(getLookAndFeel().findColour(ListBox::textColourId));
	g.setFont(font);

	MidiMessageSequence* midiSequence = rdd::MainManager::instance().getMidiSequenceManager().getMidiSequence(rowNumber);

	if (midiSequence) {
		if (columnId == 1) {
			g.drawText(juce::String(rowNumber + 1), 2, 0, width - 4, height, Justification::centredLeft, true);
		}
		//else if (columnId == 2) {
		//	g.drawText(rdd::MainManager::instance().midiSequenceManager().getMidiSequenceName(rowNumber), 2, 0, width - 4, height, Justification::centredLeft, true);
		//}
		else if (columnId == 3) {
			g.drawText(String(midiSequence->getEndTime()), 2, 0, width - 4, height, Justification::centredLeft, true);
		}


		g.setColour(getLookAndFeel().findColour(ListBox::backgroundColourId));
		g.fillRect(width - 1, 0, 1, height);

	}

}


// This is overloaded from TableListBoxModel, and must update any custom components that we're using
Component* MidiSequenceTableComponent::refreshComponentForCell(int rowNumber, int columnId, bool /*isRowSelected*/,
	Component* existingComponentToUpdate) 
{
	if (columnId == 1 || columnId == 3) // The ID and Length columns do not have a custom component
	{
		jassert(existingComponentToUpdate == nullptr);
		return nullptr;
	}

	// The other columns are editable text columns, for which we use the custom Label component
	auto* textLabel = static_cast<EditableTextCustomComponent*> (existingComponentToUpdate);

	// same as above...
	if (textLabel == nullptr)
		textLabel = new EditableTextCustomComponent(*this, rdd::MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber));
	else
		textLabel->setText(rdd::MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber), NotificationType::dontSendNotification);

	textLabel->setRowAndColumn(rowNumber, columnId);
	return textLabel;
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int MidiSequenceTableComponent::getColumnAutoSizeWidth(int columnId) 
{
	if (columnId == 1)
		return 60; // (this is the order column)
	else if (columnId == 3)
		return 60;

	int widest = this->getWidth() - 120;
	String name;

	// find the widest bit of text in this column..
	for (int i = getNumRows(); --i >= 0;)
	{

		name = rdd::MainManager::instance().getMidiSequenceManager().getMidiSequenceName(i);

		if (name.isNotEmpty())
		{
			widest = jmax(widest, font.getStringWidth(name) + 8);
		}
	}

	return widest;
}


void MidiSequenceTableComponent::selectedRowsChanged(int lastRowSelected) {
	//if (lastRowSelected == rdd::MainManager::instance().midiSequenceManager().getSelectedMidiSequenceIdx()) {
	//	rdd::MainManager::instance().midiSequenceManager().unselectMidiSequence();

	//	String s("unselecting ");
	//	s << lastRowSelected;

	//	Logger::writeToLog(s);
	//}
	//else {
	//	rdd::MainManager::instance().midiSequenceManager().selectMidiSequence(lastRowSelected);

	//	String s("selecting ");
	//	s << lastRowSelected;
	//	Logger::writeToLog(s);
	//}
}


void MidiSequenceTableComponent::cellClicked(int rowNumber, int columnId, const MouseEvent &) {

	if (rowNumber == rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceIdx()) {
		rdd::MainManager::instance().getMidiSequenceManager().unselectMidiSequence();
	}
	else {
		rdd::MainManager::instance().getMidiSequenceManager().selectMidiSequence(rowNumber);
	}

	repaint();

}


void MidiSequenceTableComponent::backgroundClicked(const MouseEvent &) {
	rdd::MainManager::instance().getMidiSequenceManager().unselectMidiSequence();

	repaint();
}


String MidiSequenceTableComponent::getText(const int columnNumber, const int rowNumber) const
{
	if (columnNumber == 2) {
		return rdd::MainManager::instance().getMidiSequenceManager().getMidiSequenceName(rowNumber);
	}
	else if (columnNumber == 1)
		return String(rowNumber + 1);
	else
		return String("whoaat");
}

void MidiSequenceTableComponent::setText(const int columnNumber, const int rowNumber, const String& newText)
{
	if (columnNumber == 2 && newText.isNotEmpty()) {
		rdd::MainManager::instance().getMidiSequenceManager().setMidiSequenceName(rowNumber, newText);
	}
}




void MidiSequenceTableComponent::updateTable() {

	table.updateContent();
	repaint();
}


//==============================================================================
void MidiSequenceTableComponent::resized() 
{
	// position our table with a gap around its edge
	table.setBoundsInset(BorderSize<int>(4));
}



//void MidiSequenceTableComponent::paint (juce::Graphics& g)
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
//    g.drawText ("MidiSequenceTableComponent", getLocalBounds(),
//                juce::Justification::centred, true);   // draw some placeholder text
//}


