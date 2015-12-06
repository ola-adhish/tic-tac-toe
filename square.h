#ifndef SQUARE_H
#define SQUARE_H

enum State
{
  NONE = 0,
  CROSS,
  CIRCLE
};

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
    char Show() const;

    // Flip
    void Flip();
};

#endif

