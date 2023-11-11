#include "Canvas.h"

ftxui::Element Canvas::CreateView()const
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

	ftxui::Element gameWindow = ftxui::window(ftxui::text("Snake"),ftxui::vbox(lines));
	ftxui::Element scoreWindow = ftxui::window(ftxui::text("score"),ftxui::text( std::to_string(score)  ));

	ftxui::Element result = ftxui::hbox(gameWindow,ftxui::vbox(scoreWindow, ftxui::filler()));

	return result;
}

void Canvas::SetBorder() 
{
	for (int x = 0; x < CANVAS_WIDTH; x++) 
	{
		SetSprite(x, CANVAS_BOUNDS.yMin, Sprite::Border);
		SetSprite(x, CANVAS_BOUNDS.yMax, Sprite::Border);
	}

	for (int y = 0; y < CANVAS_HEIGHT; y++) 
	{
		SetSprite(CANVAS_BOUNDS.xMin, y, Sprite::Border);
		SetSprite(CANVAS_BOUNDS.xMax, y, Sprite::Border);
	}
}

void Canvas::SetSprite(int index, Sprite pixel) 
{
	area.at(index).sprite = pixel;
}

void Canvas::SetSprite(int x, int y, Sprite pixel) 
{
	const int index = x + y * CANVAS_WIDTH;
	SetSprite(index, pixel);
}

void Canvas::SetSprite(Position position, Sprite pixel) 
{
	const int index = position.x + position.y * CANVAS_WIDTH;
	SetSprite(index, pixel);
}

void Canvas::AddTail(std::vector<Position> tail) 
{
	for (const auto& segmentPosition : tail) 
	{
		SetSprite(segmentPosition, Sprite::Tail);
	}
}

void Canvas::AddFruit(std::vector<Position> fruits) 
{
	for (const auto& fruit : fruits) 
	{
		SetSprite(fruit, Sprite::Fruit);
	}
}