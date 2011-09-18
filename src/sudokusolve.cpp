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

#include <libsudoku/sudokusolver.hpp>

using namespace sudoku;

// "star burst leo", http://en.wikipedia.org/wiki/Sudoku_algorithms
static const int star_burst_leo []={
9,0,0,1,0,4,0,0,2,
0,8,0,0,6,0,0,7,0,
0,0,0,0,0,0,0,0,0,
4,0,0,0,0,0,0,0,1,
0,7,0,0,0,0,0,3,0,
3,0,0,0,0,0,0,0,7,
0,0,0,0,0,0,0,0,0,
0,3,0,0,7,0,0,8,0,
1,0,0,2,0,9,0,0,4
};

int main(int argc, char* argv[]) {
  SudokuSolver* s = new SudokuSolver(star_burst_leo);
  Gecode::DFS<SudokuSolver> e(s);
  delete s;
  while (SudokuSolver* result = e.next()) {
    result->print(std::cout);
    delete result;
  }
  return 0;
}
