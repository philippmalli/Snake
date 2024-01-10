#pragma once

#include "Boundary.h"
#include <cstdint>

constexpr uint8_t CANVAS_WIDTH = 15;
constexpr uint8_t CANVAS_HEIGHT = 20;

constexpr Boundary CANVAS_BOUNDS{ .xMin = 0, .xMax = CANVAS_WIDTH - 1, .yMin = 0, .yMax = CANVAS_HEIGHT - 1 };

enum class GameAction
{
  Continue,
  ExitGame
};