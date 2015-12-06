#include "square.h"

Square::Square()
{
  _state = NONE;
}

Square::Square(State state)
{
  _state = state;
}

Square::Square(int state)
{
  switch(state)
    {
    case 1:
      _state = CROSS;
      break;
    case 2:
      _state = CIRCLE;
      break;
    default:
      _state = NONE;
    }
}

Square::~Square()
{ }

void Square::SetState(State state)
{
  _state = state;
}

void Square::SetState(int state)
{
  switch(state)
    {
    case 1:
      _state = CROSS;
      break;
    case 2:
      _state = CIRCLE;
      break;
    default:
      _state = NONE;
    }
}

void Square::Reset()
{
  _state = NONE;
}

State Square::GetState() const
{
  return _state;
}

char Square::Show() const
{
  switch(_state)
    {
    case CROSS:
      return 'X';
    case CIRCLE:
      return 'O';
    case NONE:
    default:
      return ' ';
    }
}

void Square::Flip()
{
  switch(_state)
    {
    case CROSS:
      _state = CIRCLE;
      break;
    case CIRCLE:
      _state = CROSS;
      break;
    case NONE:
    default:
      break;
    }
}
