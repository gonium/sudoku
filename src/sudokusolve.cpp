/*
 * TODO: GPL header
*
 */

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

class SudokuSolver : public Script {
  protected:
    IntVarArray sudoku_array;
  public:
    SudokuSolver(const Options& opt)
      : sudoku_array(*this, 9*9, 1, 9)
    {
      Matrix<IntVarArray> m(sudoku_array, 9, 9);

      for(int i=0; i<9; i++)
        distinct(*this, m.row(i));
      for(int i=0; i<9; i++)
        distinct(*this, m.col(i));
      for(int i=0; i<9; i+=3)
        for(int j=0; j<9; j+=3)
          distinct(*this, m.slice(i, i+3, j, j+3));

      branch(*this, sudoku_array, INT_VAR_SIZE_MIN, INT_VAL_MIN);
    }
    SudokuSolver(bool share, SudokuSolver& s)
      : Script(share, s) {
        sudoku_array.update(*this, share, s.sudoku_array);
      }
    virtual Space* copy(bool share) {
      return new SudokuSolver(share,*this);
    }
    virtual void print(std::ostream& os) const {
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
};

int main(int argc, char* argv[]) {
  // commandline options
  Options opt("SudokuSolver");
  opt.solutions(0);
  opt.parse(argc,argv);
  // run script
  Script::run<SudokuSolver,DFS,Options>(opt);
  return 0;
}
