#include "square.h"

Square::Square()
{
  _state = State::NONE;
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
      _state = State::CROSS;
      break;
    case 2:
      _state = State::CIRCLE;
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
      _state = State::CROSS;
      break;
    case 2:
      _state = State::CIRCLE;
      break;
    default:
      _state = NONE;
    }
}

void Square::Reset()
{
  _state = State::NONE;
}

State Square::GetState() const
{
  return _state;
}

char Square::Show() const
{
  switch(_state)
    {
    case State::CROSS:
      return 'X';
    case State::CIRCLE:
      return 'O';
    case State::NONE:
    default:
      return ' ';
    }
}

void Square::Flip()
{
  switch(_state)
    {
    case State::CROSS:
      _state = State::CIRCLE;
      break;
    case State::CIRCLE:
      _state = State::CROSS;
      break;
    case State::NONE:
    default:
      break;
    }
}
