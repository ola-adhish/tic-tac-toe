#include "board.h"

Board::Board(int dim)
{
  SetDim(dim);
}

Board::~Board()
{
  for (int i=0; i<_dim; ++i)
    {
      delete _squares[i];
      _squares[i] = NULL;
    }

  delete _squares;
  _squares = NULL;
}

bool Board::_isValidIndex(int index) const
{
  return ((index > 0) && (index <= _dim));
}

bool Board::SetSquare(int row, int col, State value)
{
  if (_isValidIndex(row) && _isValidIndex(col))
    {
      _squares[row-1][col-1] = value;
      return true;
    }
  else
    {
      return false;
    }
}

void Board::SetDim(int dim)
{
  if (dim >= 3)
    {
      _dim = dim;
      _squares = new Square*[_dim];
      for (int i=0; i<_dim; ++i)
	{
	  _squares[i] = new Square[_dim];
	}
      Reset();
    }
  else
    {
      _dim = 0;
    }
}

void Board::Reset()
{
  for (int i=0; i<_dim; ++i)
    {
      for (int j=0; j<_dim; ++j)
	{
	  _squares[i][j].SetState(NONE);
	}
    }
}

State Board::GetState(int row, int col) const
{
  if (_isValidIndex(row) && _isValidIndex(col))
    {
      return _squares[row-1][col-1].GetState();
    }
  else
    {
      std::cout << "Invalid indices ["<< row << ", " << col << "]." << std::endl;
      return NONE;
    }
}

State Board::IsWinner() const
{
  int i, j;
  bool crosses_rows;
  bool circles_rows;
  bool crosses_cols;
  bool circles_cols;

  // Check rows and columns first  
  for (i=0; i<_dim; ++i)
  {
      crosses_rows = true;
      circles_rows = true;
      crosses_cols = true;
      circles_cols = true;
      for (j=0; j<_dim; ++j)
	  {
		State row_state = _squares[i][j].GetState();
		State col_state = _squares[j][i].GetState();

		crosses_rows = crosses_rows && (row_state == CROSS);
		circles_rows = circles_rows && (row_state == CIRCLE);

		crosses_cols = crosses_cols && (col_state == CROSS);
		circles_cols = circles_cols && (col_state == CIRCLE);
	  }

      if (crosses_rows || crosses_cols)
	  {
		return CROSS;
	  }
      
      if (circles_rows || circles_cols)
	  {
		return CIRCLE;
	  }
    }

  // Check diagonals
  bool crosses_prime = true;
  bool circles_prime = true;
  bool crosses_antip = true;
  bool circles_antip = true;
  for (i=0; i<_dim; ++i)
    {
      State prime_state = _squares[i][i].GetState();
      State antip_state = _squares[_dim-i-1][_dim-i-1].GetState();
      crosses_prime = crosses_prime && (prime_state == CROSS);
      circles_prime = circles_prime && (prime_state == CIRCLE);
      crosses_antip = crosses_antip && (antip_state == CROSS);
      circles_antip = circles_antip && (antip_state == CIRCLE);
    }
  if (crosses_prime || crosses_antip)
    {
      return CROSS;
    }
  
  if (circles_prime || circles_antip)
    {
      return CIRCLE;
    }
  
  return NONE;
}

int Board::GetDim() const
{
  return _dim;
}

void Board::Show() const
{
  std::cout << std::endl;

  for (int i=0; i < _dim-1; ++i)
  {
	  for (int j=0; j < _dim-1; ++j)
	  {
		  std::cout << _squares[i][j].Show() << "|";
	  }
      std::cout << _squares[i][_dim-1].Show() << std::endl;
      for (int k=0; k<((2*_dim)-1); ++k)
	  {
		  std::cout << "_";
	  }
      std::cout << std::endl;
  }

  for (int j=0; j < _dim-1; ++j)
  {
	  std::cout << _squares[_dim-1][j].Show() << "|";
  }
  std::cout << _squares[_dim-1][_dim-1].Show() << std::endl;
}
