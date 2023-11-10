#pragma once
#include <queue>
#include "KeyMapping.h"
#include "Position.h"
#include "Constants.h"
#include <vector>
#include <mutex>
#include <atomic>

/// <summary>
/// enum to define travel direction of player character
/// </summary>
enum class Direction { None, Up, Down, Left, Right };

class Player
{
public:
	/// <summary>
	/// current position of player character
	/// </summary>
	Position position { CANVAS_WIDTH/2, CANVAS_HEIGHT/2};

	/// <summary>
	/// current direction of player character
	/// </summary>
	Direction currentDirection{ Direction::None };

	/// <summary>
	/// List of positions of tail segments
	/// </summary>
	std::vector<Position> tail {};

	/// <summary>
	/// flag if a new tail segment should be added on next move
	/// </summary>
	bool shouldAddSegment { false };
	
	/// <summary>
	/// constructor
	/// </summary>
	Player()
	{}

	/// <summary>
	/// Get position of head
	/// </summary>
	/// <returns></returns>
	inline Position GetHeadPosition() const
	{
		return position;
	}

	/// <summary>
	/// get position of tail  segmments
	/// </summary>
	/// <returns></returns>
	inline std::vector<Position> GetTail() const
	{
		return tail;
	}

	/// <summary>
	/// update Player character based on pressed key
	/// </summary>
	void UpdatePosition();

	/// <summary>
	/// update nextDirection based on keyboard input
	/// </summary>
	/// <param name="key"></param>
	void NewInput(KeyAction key);

	/// <summary>
	/// get all Collider positions for the tail
	/// </summary>
	/// <returns></returns>
	std::vector<Position> GetTailCollider() const;

	bool ColllidedWithEdge() const;

private:
	std::atomic<Direction> nextDirection{ Direction::None };

	void UpdateDirection();

	bool MoveHead();
	void MoveTail();
};

