#include "Canvas.h"

std::string Canvas::Draw() const
{
	int currentCursorPositonX = 0;

	std::stringstream stream;

	for (CanvasItem item : area) 
	{
		stream << item.GetCharacter() << ' ';
		if (++currentCursorPositonX >= CANVAS_WIDTH) 
		{
			stream << "\n";
			currentCursorPositonX = 0;
		}
	}

	return stream.str();
}

std::vector<std::string> Canvas::GenerateView() const
{
	std::vector<std::string> result {};
	int currentCursorPositonX = 0;

	std::stringstream stream;

	for (CanvasItem item : area) 
	{
		stream << item.GetCharacter() << ' ';
		if (++currentCursorPositonX >= CANVAS_WIDTH) 
		{
			result.push_back(stream.str());
			stream.str(""); 
			currentCursorPositonX = 0;
		}
	}

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