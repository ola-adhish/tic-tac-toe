#ifndef SQUARE_H
#define SQUARE_H

#include "state.h"

class Square
{
  protected:
    State _state;
  public:
    // Constructors
    Square();
    Square(State state);
    Square(int state);

    // Destructor
    virtual ~Square();

    // Set - Reset
    void SetState(State state);
    void SetState(int state);
    void Reset();

    // Get
    State GetState() const;

    // Flip
    void Flip();
}

#endif

