#pragma once

/// <summary>
/// enum to define different types of character sprites
/// </summary>
enum class Sprite {Empty, Border, Player, Tail, Fruit};

/// <summary>
/// wrapper for sprite enum that generates corresponding character
/// </summary>
class CanvasItem
{
public:
	/// <summary>
	/// the set sprite
	/// </summary>
	Sprite sprite{ Sprite::Empty };

	/// <summary>
	/// retrieve corresponding character for Sprite
	/// </summary>
	/// <returns></returns>
	char GetCharacter() const;
};

