/*
  ==============================================================================

    MidiSequenceTableComponent.h
    Created: 9 Oct 2020 8:41:10pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MidiSequenceTableComponent  : public juce::Component, public juce::TableListBoxModel
{
public:
    MidiSequenceTableComponent();
    ~MidiSequenceTableComponent() override;

	// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
	int getNumRows() override;

	// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
	void paintRowBackground(Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected) override;

	// This is overloaded from TableListBoxModel, and must paint any cells that aren't using custom
// components.
	void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool /*rowIsSelected*/) override;

	// This is overloaded from TableListBoxModel, and must update any custom components that we're using
	Component* refreshComponentForCell(int rowNumber, int columnId, bool /*isRowSelected*/,
		Component* existingComponentToUpdate) override;

	// This is overloaded from TableListBoxModel, and should choose the best width for the specified
	// column.
	int getColumnAutoSizeWidth(int columnId) override;

	void selectedRowsChanged(int lastRowSelected) override;

	void cellClicked(int rowNumber, int columnId, const MouseEvent &) override;
	void backgroundClicked(const MouseEvent &) override;


	String getText(const int columnNumber, const int rowNumber) const;

	void setText(const int columnNumber, const int rowNumber, const String& newText);

	void updateTable();


   // void paint (juce::Graphics&) override;
    void resized() override;

private:

	TableListBox table;     // the table component itself
	Font font{ 14.0f };

		    //==============================================================================
    // This is a custom Label component, which we use for the table's editable text columns.
    class EditableTextCustomComponent  : public juce::Label
    {
    public:
        EditableTextCustomComponent (MidiSequenceTableComponent& td, String name)  : owner (td)
        {
            // double click to edit the label text; single click handled below
            setEditable (false, true, false);
			setText(name, NotificationType::dontSendNotification);
        }

        void mouseDown (const MouseEvent& event) override
        {
            // single click on the label should simply select the row
			owner.cellClicked(row, columnId, event);//.table.selectRowsBasedOnModifierKeys(row, event.mods, false);

            Label::mouseDown (event);
        }

        void textWasEdited() override
        {
            owner.setText (columnId, row, getText());
        }

        // Our demo code will call this when we may need to update our contents
        void setRowAndColumn (const int newRow, const int newColumn)
        {
            row = newRow;
            columnId = newColumn;
           // setText (owner.getText(columnId, row), dontSendNotification);
        }

        void paint (Graphics& g) override
        {
            auto& lf = getLookAndFeel();
            if (! dynamic_cast<LookAndFeel_V4*> (&lf))
                lf.setColour (textColourId, Colours::black);

            Label::paint (g);
        }

    private:
		MidiSequenceTableComponent& owner;
        int row, columnId;
        Colour textColour;
    };


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiSequenceTableComponent)
};
