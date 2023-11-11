#pragma once

enum class Sprite
{
  Empty,
  Border,
  Player,
  Tail,
  Fruit
};

class CanvasItem
{
public:
  Sprite sprite{ Sprite::Empty };

  char GetCharacter() const;
};