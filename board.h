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
  Board(int dim=0);
  // Destructor
  virtual ~Board();

  // Setters
  bool SetSquare(int row, int col, State value);
  void SetDim(int dim);
  void Reset();
  
  // Getters
  State GetState(int row, int col) const;
  int GetDim() const;
  State IsWinner() const;
    
  // Display
  void Show() const;
};

#endif
