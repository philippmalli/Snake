#include "Player.h"

void Player::UpdatePosition()
{
	UpdateDirection();

	bool didMove = MoveHead();
	if (didMove)
	{
		MoveTail();
	}
}

std::vector<Position> Player::GetTailCollider() const
{
	if (tail.empty())
	{
		return std::vector<Position>();		
	}
	return std::vector<Position>(tail.begin(), tail.end() - 1);
}

void Player::UpdateDirection()
{
	currentDirection = nextDirection;
}

bool Player::MoveHead()
{
	const Position old = position;
	switch (currentDirection)
	{
	case Direction::Up:
		position.y--;
		break;
	case Direction::Down:
		position.y++;
		break;
	case Direction::Left:
		position.x--;
		break;
	case Direction::Right:
		position.x++;
		break;
	default:
		break;
	}

	return (position != old);
}

void Player::MoveTail()
{
	if (!shouldAddSegment)
	{
		if (!tail.empty())
		{
			tail.erase(tail.begin());
		}
	}
	tail.push_back(position);
	shouldAddSegment = false;
}

bool Player::ColllidedWithEdge() const
{
	if (position.x <= CANVAS_BOUNDS.xMin)
	{
		return true;
	}

	if (position.x >= CANVAS_BOUNDS.xMax)
	{
		return true;
	}

	if (position.y <= CANVAS_BOUNDS.yMin)
	{
		return true;
	}

	if (position.y >= CANVAS_BOUNDS.yMax)
	{
		return true;
	}

	return false;

}

void Player::NewInput(KeyAction key)
{
	switch (key)
	{
	case KeyAction::Up:
		nextDirection = Direction::Up;
		break;
	case KeyAction::Down:
		nextDirection = Direction::Down;
		break;
	case KeyAction::Left:
		nextDirection = Direction::Left;
		break;
	case KeyAction::Right:
		nextDirection = Direction::Right;
		break;
	default:
		break;
	}
}