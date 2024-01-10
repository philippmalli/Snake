#include "Canvas.h"

void Canvas::Clear()
{
  area.fill(CanvasItem());
  score = 0;
}

ftxui::Element Canvas::CreateView() const
{
  auto mainContent = GenerateCanvasText();

  ftxui::Element gameWindow = ftxui::window(ftxui::text("Snake"), mainContent);
  ftxui::Element scoreWindow = ftxui::window(ftxui::text("score"), ftxui::text(std::to_string(score)));

  ftxui::Element result = ftxui::hbox(gameWindow, ftxui::vbox(scoreWindow, ftxui::filler()));

  return result;
}

ftxui::Element Canvas::CreateGameOverScreen() const
{
  auto mainContent = GenerateCanvasText();

  ftxui::Element gameWindow = ftxui::window(ftxui::text("Game Over"), mainContent);
  ftxui::Element scoreWindow = ftxui::window(ftxui::text("score"), ftxui::text(std::to_string(score)));

  ftxui::Element result = ftxui::hbox(gameWindow, ftxui::vbox(scoreWindow, ftxui::filler()));

  return result;
}


void Canvas::SetBorder()
{
  for (int x = 0; x < CANVAS_WIDTH; x++)
  {
    SetSprite(Position(x, CANVAS_BOUNDS.yMin), Sprite::Border);
    SetSprite(Position(x, CANVAS_BOUNDS.yMax), Sprite::Border);
  }

  for (int y = 0; y < CANVAS_HEIGHT; y++)
  {
    SetSprite(Position(CANVAS_BOUNDS.xMin, y), Sprite::Border);
    SetSprite(Position(CANVAS_BOUNDS.xMax, y), Sprite::Border);
  }
}

void Canvas::SetSprite(int linearIndex, Sprite pixel) { area.at(linearIndex).sprite = pixel; }

void Canvas::SetSprite(const Position &position, Sprite pixel)
{
  const int index = position.x + position.y * CANVAS_WIDTH;
  SetSprite(index, pixel);
}

void Canvas::AddTail(std::vector<Position> tail)
{
  for (const auto &segmentPosition : tail) { SetSprite(segmentPosition, Sprite::Tail); }
}

void Canvas::AddFruit(std::vector<Position> fruits)
{
  for (const auto &fruit : fruits) { SetSprite(fruit, Sprite::Fruit); }
}

ftxui::Element Canvas::GenerateCanvasText() const
{
  ftxui::Elements lines;

  int currentCursorPositonX = 0;

  std::stringstream stream;

  for (CanvasItem item : area)
  {
    stream << item.GetCharacter() << ' ';
    if (++currentCursorPositonX >= CANVAS_WIDTH)
    {
      lines.push_back(ftxui::text(stream.str()));
      stream.str("");
      currentCursorPositonX = 0;
    }
  }

  return ftxui::vbox(lines);
}