#include "KeyMapping.h"

KeyAction getKeyActionFromEvent(ftxui::Event event)
{
	if(event == ftxui::Event::ArrowDown)
	{
		return KeyAction::Down;
	}

	if(event == ftxui::Event::ArrowUp)
	{
		return KeyAction::Up;
	}

	if(event == ftxui::Event::ArrowLeft)
	{
		return KeyAction::Left;
	}

	if(event == ftxui::Event::ArrowRight)
	{
		return KeyAction::Right;
	}

	if(event.is_character() && event.character() == "x" )
	{
		return KeyAction::Exit;
	}

	return KeyAction::Any;
}