/**
 * This file is part of sudoku.
 *
 * (c) Mathias Dalheimer <md@gonium.net>, 2011
 *
 * sudoku is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * sudoku is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with sudoku. If not, see <http://www.gnu.org/licenses/>.
 *
 */

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

