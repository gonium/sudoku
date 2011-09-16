/*
 * TODO: GPL header
*
 */

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

// "star burst leo", http://en.wikipedia.org/wiki/Sudoku_algorithms
static const int sudoku1 []={
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

class SudokuSolver : public Script {
  protected:
    IntVarArray sudoku_array;
  public:
    SudokuSolver(const Options& opt)
      : sudoku_array(*this, 9*9, 1, 9)
    {
      Matrix<IntVarArray> m(sudoku_array, 9, 9);

      std::cout << "Setup: Using sudoku1" << std::endl;
      for (int i=0; i<9; i++){
        for (int j=0; j<9; j++) {
          int v = sudoku1[i*9 + j];
          std::cout << " " << v;
          if (v != 0)
            rel(*this, m(j,i), IRT_EQ, v );
        }
        std::cout << std::endl;
      }


      for(int i=0; i<9; i++)
        distinct(*this, m.row(i));
      for(int i=0; i<9; i++)
        distinct(*this, m.col(i));
      for(int i=0; i<9; i+=3)
        for(int j=0; j<9; j+=3)
          distinct(*this, m.slice(i, i+3, j, j+3));

      std::cout << "Setup of constraints complete." << std::endl << std::endl;

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
