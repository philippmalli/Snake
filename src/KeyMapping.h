#pragma once

#include <string>
#include "ftxui/component/event.hpp"

enum class KeyAction {Up, Down, Left, Right, Exit, Any};

KeyAction getKeyActionFromEvent(ftxui::Event event);