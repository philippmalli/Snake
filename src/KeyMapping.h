#pragma once

#include "ftxui/component/event.hpp"
#include <string>

enum class KeyAction
{
  Up,
  Down,
  Left,
  Right,
  Exit,
  Any
};

KeyAction getKeyActionFromEvent(ftxui::Event event);