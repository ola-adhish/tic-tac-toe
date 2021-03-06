#include "game.h"

Game::Game(int d)
{
  _board = new Board(d);
  _dim = d;
  _gameOver = false;
}

Game::~Game()
{
  if (_board != NULL)
    {
      delete _board;
      _board = NULL;
    }
}

void Game::Play()
{
	_gameOver = false;
	Square* _player = new Square(CROSS);
	int row, col;
	
	while (!_gameOver)
	{
		bool ok;
		do
		{
			std::cout << "Player " << _player->Show() << ": ";
			std::cin >> row >> col;
			
			switch(_board->GetState(row, col))
			{
				case NONE:
					ok = _board->SetSquare(row, col, _player->GetState());			
					if (ok)
					{
						_player->Flip();
					}
					break;
				case CROSS:
				case CIRCLE:
					std::cout << "This square is already taken !" << std::endl;
					ok = false;
					break;
			}
		} while (!ok);
		
		_board->Show();
		State winner = _board->IsWinner();
		_gameOver = (winner != NONE);
	}
}

void Game::Reset()
{
  _board->Reset();
}
