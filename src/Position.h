#pragma once
#include <compare>
#include <cstdint>

struct Position
{
  uint16_t x{ 0 };
  uint16_t y{ 0 };

  friend auto operator<=>(const Position &, const Position &) = default;
};