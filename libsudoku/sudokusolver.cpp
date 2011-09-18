#include "sudokusolver.hpp"

using namespace sudoku;
using namespace Gecode;

SudokuSolver::SudokuSolver(const int sudokuproblem[])
: sudoku_array(*this, 9*9, 1, 9)
{
  Matrix<IntVarArray> m(sudoku_array, 9, 9);

  std::cout << "Setup - Using this sudoku:" << std::endl;
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++) {
      int v = sudokuproblem[i*9 + j];
      std::cout << " " << v;
      if (v != 0)
        rel(*this, m(j,i), IRT_EQ, v );
    }
    std::cout << std::endl;
  }


  std::cout << "Setup - row constraints" << std::endl;
  for(int i=0; i<9; i++)
    distinct(*this, m.row(i));
  std::cout << "Setup - column constraints" << std::endl;
  for(int i=0; i<9; i++)
    distinct(*this, m.col(i));
  std::cout << "Setup - square constraints" << std::endl;
  for(int i=0; i<9; i+=3)
    for(int j=0; j<9; j+=3)
      distinct(*this, m.slice(i, i+3, j, j+3));

  branch(*this, sudoku_array, INT_VAR_SIZE_MIN, INT_VAL_MIN);
}

SudokuSolver::SudokuSolver(bool share, SudokuSolver& s)
  : Script(share, s) {
    sudoku_array.update(*this, share, s.sudoku_array);
  }

Space* SudokuSolver::copy(bool share) {
  return new SudokuSolver(share,*this);
}

void SudokuSolver::print(std::ostream& os) const {
  os << "  ";
  for (int i = 0; i<9*9; i++) {
    if (sudoku_array[i].assigned())
      os << sudoku_array[i] << " ";
    else
      os << ". ";
    if((i+1)%(9) == 0)
      os << std::endl << "  ";
  }
  os << std::endl;

}


