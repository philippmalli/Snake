#pragma once

#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <thread>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include "Canvas.h"
#include "Constants.h"
#include "KeyboardInputHandler.h"
#include "Player.h"

enum class CollisionResult
{
  Collision,
  NoCollision
};

class GameController
{
public:
  GameController() {}

  void Run();

  ftxui::Element currentView{};

  std::vector<std::string> currentOutputText{};

private:
  Player snake{};
  std::vector<Position> fruits{};
  int turnsSinceFruitSpawn{ 0 };
  int score{ 0 };
  std::atomic<GameAction> action{ GameAction::Continue };
  std::random_device randomDevice{};
  std::mt19937 rngEngine = std::mt19937(randomDevice());
  std::uniform_int_distribution<uint16_t> rngDistX{ CANVAS_BOUNDS.xMin + 1, CANVAS_BOUNDS.xMax - 1 };
  std::uniform_int_distribution<uint16_t> rngDistY{ CANVAS_BOUNDS.yMin + 1, CANVAS_BOUNDS.yMax - 1 };

  void SpawnFruit();

  void HandleCollision();

  CollisionResult DetectCollison(const Position &playerPosition, const std::vector<Position> &colliders) const;

  void HandleCollisionFruit(const Position &playerPosition);

  void Draw();

  int CalculateScoreIncrement();
};
