#pragma once

#include "Constants.h"
#include "KeyMapping.h"
#include "Position.h"
#include <atomic>
#include <vector>

enum class Direction
{
  None,
  Up,
  Down,
  Left,
  Right
};

class Player
{
public:
  Position position{ CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 };
  Direction currentDirection{ Direction::None };
  std::vector<Position> tail{};
  bool shouldAddSegment{ false };

  Player() {}

  inline Position GetHeadPosition() const { return position; }

  inline std::vector<Position> GetTail() const { return tail; }

  void UpdatePosition();
  void NewInput(KeyAction key);
  std::vector<Position> GetTailCollider() const;
  bool ColllidedWithEdge() const;

private:
  std::atomic<Direction> nextDirection{ Direction::None };

  void UpdateDirection();
  bool MoveHead();
  void MoveTail();

  bool IsNewDirectionValid() const;
};