#include "KeyMapping.h"

KeyAction getKeyActionFromChar(char enteredCharacter)
{
	switch (enteredCharacter)
	{
	case 'w':
		return KeyAction::Up;
	case 'a':
		return KeyAction::Left;
	case 's':
		return KeyAction::Down;
	case 'd':
		return KeyAction::Right;
	case 'x':
		return KeyAction::Exit;
	}
	return KeyAction::Any;
}

std::string keyActionToString(KeyAction keyAction)
{
	switch (keyAction)
	{
	case KeyAction::Any:
		return "Any";
	case KeyAction::Up:
		return "Up";
	case KeyAction::Down:
		return "Down";
	case KeyAction::Left:
		return "Left";
	case KeyAction::Right:
		return "Right";
	case KeyAction::Exit:
		return "Exit";
	}
	return " ";
}

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