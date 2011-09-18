#ifndef LIBSUDOKU_SUDOKUSOLVER_HPP
#define LIBSUDOKU_SUDOKUSOLVER_HPP 1

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

namespace sudoku {

  class SudokuSolver : public Gecode::Script {
    protected:
      Gecode::IntVarArray sudoku_array;
    public:
      SudokuSolver(const int sudokuproblem[]);
      SudokuSolver(bool share, SudokuSolver& s);
      virtual Gecode::Space* copy(bool share); 
      virtual void print(std::ostream& os) const;
  };

};

#endif /* LIBSUDOKU_SUDOKUSOLVER_HPP */

