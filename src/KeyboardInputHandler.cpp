#include "KeyboardInputHandler.h"

void KeyboardInputHandler::ProcessInput(ftxui::Event event) const
{
  const auto keyAction = getKeyActionFromEvent(event);

  if (keyAction == KeyAction::Exit)
  {
    action = GameAction::ExitGame;
    return;
  }
  player.NewInput(keyAction);
}