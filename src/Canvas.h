#pragma once
#include <string>
#include <sstream>
#include <array>
#include <vector>

#include "Constants.h"
#include "CanvasItem.h"
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
	std::array<CanvasItem, CANVAS_WIDTH * CANVAS_HEIGHT> area;

	/// <summary>
	/// set the positions of "border" sprites
	/// </summary>
	void SetBorder();

	/// <summary>
	/// set position of "player" sprite
	/// </summary>
	/// <param name="position"></param>
	inline void AddPlayer(Position position)
	{
		SetSprite(position, Sprite::Player);
	}

	/// <summary>
	/// set postions of "tail" sprites
	/// </summary>
	/// <param name="tail"></param>
	void AddTail(std::vector<Position> tail);

	/// <summary>
	/// set positions of "fruit" sprites
	/// </summary>
	/// <param name="fruits"></param>
	void AddFruit(std::vector<Position> fruits);

	/// <summary>
	/// draw all elements on playing field to screen
	/// </summary>
	std::string Draw() const;

	std::vector<std::string> GenerateView() const;

private:
	/// <summary>
	/// set a sprite directly on playing field
	/// </summary>
	/// <param name="index"></param>
	/// <param name="pixel"></param>
	void SetSprite(int index, Sprite pixel);

	/// <summary>
	/// set a sprite on playing field with given coordinnates
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="pixel"></param>
	void SetSprite(int x, int y, Sprite pixel);

	/// <summary>
	/// set sprite with given position
	/// </summary>
	/// <param name="position"></param>
	/// <param name="pixel"></param>
	void SetSprite(Position position, Sprite pixel);

	/// <summary>
	/// clears the terminal screen. Works on Windows only
	/// </summary>
	static void ClearScreen();
};