#include "CanvasItem.h"

char CanvasItem::GetCharacter() const
{
  switch (sprite)
  {
  case Sprite::Empty:
    return ' ';
  case Sprite::Border:
    return '#';
  case Sprite::Player:
    return '@';
  case Sprite::Tail:
    return 'O';
  case Sprite::Fruit:
    return 'g';
  }
  return ' ';
}