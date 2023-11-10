#pragma once

#include "ftxui/component/event.hpp"

#include "KeyMapping.h"
#include "Constants.h"
#include "Player.h"

/// <summary>
/// get input from keyboard and push keys to queue
/// </summary>
class KeyboardInputHandler
{
public:
	Player& player;

	std::atomic<GameAction>& action;

	/// <summary>
	/// construcor
	/// </summary>
	/// <param name="queue"></param>
	KeyboardInputHandler(Player& playerObj, std::atomic<GameAction>& gameAction) : player(playerObj), action(gameAction)
	{}

	/// <summary>
	/// start listening loop, terminates on "exit" key
	/// </summary>
	/// <returns></returns>
	void Listen() const;

	void ProcessInput(ftxui::Event event) const;
};