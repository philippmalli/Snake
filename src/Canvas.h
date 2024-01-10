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
  void Clear();

  void SetBorder();

  inline void AddPlayer(Position position) { SetSprite(position, Sprite::Player); }

  void AddTail(std::vector<Position> tail);

  void AddFruit(std::vector<Position> fruits);

  void SetScore(int score) { this->score = score; }

  ftxui::Element CreateView() const;

  ftxui::Element CreateGameOverScreen() const;

private:
  /// @brief 1-D array to represent every slot of the playing field
  std::array<CanvasItem, CANVAS_WIDTH * CANVAS_HEIGHT> area{};

  /// @brief the score to be displayed
  int score{ 0 };

  void SetSprite(int linearIndex, Sprite pixel);

  void SetSprite(const Position &position, Sprite pixel);

  ftxui::Element GenerateCanvasText() const;
};