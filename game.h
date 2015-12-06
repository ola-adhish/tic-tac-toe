#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <iostream>

class Game
{
 protected:
  Board* _board;
  int _dim;
  bool _gameOver;
  
 public:
  Game(int d);
  ~Game();

  void Play();
  void Reset();
};

#endif

