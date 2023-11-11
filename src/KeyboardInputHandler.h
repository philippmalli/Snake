#pragma once

#include "ftxui/component/event.hpp"

#include "Constants.h"
#include "KeyMapping.h"
#include "Player.h"

class KeyboardInputHandler
{
public:
  Player &player;

  std::atomic<GameAction> &action;

  KeyboardInputHandler(Player &playerObj, std::atomic<GameAction> &gameAction) : player(playerObj), action(gameAction)
  {
  }

  void ProcessInput(ftxui::Event event) const;
};