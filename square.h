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
    virtual ~State();

    // Set
    
}

#endif

