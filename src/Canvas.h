#pragma once
#include <array>
#include <sstream>
#include <string>
#include <vector>

#include "ftxui/dom/elements.hpp"

#include "CanvasItem.h"
#include "Constants.h"
#include "Position.h"

/// <summary>
/// Class that draws all game object to console
/// </summary>
class Canvas
{
public:
  /// <summary>
  /// 1-D array to represent every slot of the playing field
  /// </summary>
  std::array<CanvasItem, CANVAS_WIDTH * CANVAS_HEIGHT> area{};

  void SetBorder();

  inline void AddPlayer(Position position) { SetSprite(position, Sprite::Player); }

  void AddTail(std::vector<Position> tail);

  void AddFruit(std::vector<Position> fruits);

  void SetScore(int score) { this->score = score; }

  ftxui::Element CreateView() const;

  ftxui::Element CreateGameOverScreen() const;

private:
  int score{ 0 };

  void SetSprite(int index, Sprite pixel);

  void SetSprite(int x, int y, Sprite pixel);

  void SetSprite(Position position, Sprite pixel);

  static void ClearScreen();
};