#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "square.h"

class Board
{
 protected:
  Square** _squares;
  int _dim;

  bool _isValidIndex(int index) const;
    
 public:
  // Constructors
  Board(int dim);
  // Destructor
  virtual ~Board();

  // Setters
  bool SetSquare(int row, int col, State value);
  void Reset();
  
  // Getters
  State GetState(int row, int col) const;
  State IsWinner() const;
    
  // Display
  void Show() const;
};

#endif
