#pragma once

#include <random>
#include <chrono>
#include <algorithm>
#include <string>
#include <thread>

#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/component/component.hpp"       // for CatchEvent, Renderer
#include "ftxui/dom/elements.hpp"  // for text, vbox, window, Element, Elements
#include "ftxui/component/loop.hpp"       // for Loop

#include "Canvas.h"
#include "Player.h"
// #include "KeyboardListener.h"
#include "Constants.h"
#include "KeyboardInputHandler.h"

/// <summary>
/// Enum for state of Collision detection
/// </summary>
enum class CollisionResult { Collision, NoCollision };

/// <summary>
/// class that contro�s the flow of tthe game
/// </summary>
class GameController
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	GameController()
	{
		std::random_device randomDevice;
		rngEngine = std::mt19937(randomDevice());
	}

	/// <summary>
	/// start the game
	/// </summary>
	void Run();

	std::vector<std::string> currentOutputText {};

private:
	/// <summary>
	/// player character
	/// </summary>
	Player snake{};

	/// <summary>
	/// list of fruit  on playing field
	/// </summary>
	std::vector<Position> fruits{};

	/// <summary>
	/// number of turns since a fruit spawned
	/// </summary>
	int turnsSinceFruitSpawn{ 0 };

	/// <summary>
	/// score
	/// </summary>
	int score{ 0 };

	/// <summary>
	/// thread safe game action state (continue, exit, ...)
	/// </summary>
	std::atomic<GameAction> action{ GameAction::Continue };

	/// <summary>
	/// randomness engine for creatin random numbers
	/// </summary>
	std::mt19937 rngEngine{};

	/// <summary>
	/// rng distribution for x coordinnates on playing field
	/// </summary>
	std::uniform_int_distribution<uint16_t> rngDistX{ CANVAS_BOUNDS.xMin + 1,CANVAS_BOUNDS.xMax - 1 };

	/// <summary>
	/// rng distribution for y coordinnates on playing field
	/// </summary>
	std::uniform_int_distribution<uint16_t> rngDistY{ CANVAS_BOUNDS.yMin + 1,CANVAS_BOUNDS.yMax - 1 };
	
	/// <summary>
	/// spawn a new fruit on playing field
	/// </summary>
	void SpawnFruit();

	/// <summary>
	/// handle eventual collissions of player charater with fruits, walls, tail
	/// </summary>
	void HandleCollision();

	/// <summary>
	/// detect if the position of the player character is the same as any of the collider positions
	/// </summary>
	/// <param name="playerPosition"></param>
	/// <param name="colliders"></param>
	/// <returns></returns>
	CollisionResult DetectCollison(const Position& playerPosition, const std::vector<Position> colliders) const;

	/// <summary>
	/// handle the event of a collision with a fruit
	/// </summary>
	/// <param name="playerPosition"></param>
	void HandleCollisionFruit(const Position& playerPosition);

	/// <summary>
	/// draw all game objects to screen
	/// </summary>
	void Draw();

	int GetScore();
};

