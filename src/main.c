#include <stdio.h>
#include "gaussian_elimination.h"
#include "ui.h"

int main() {
    /* Expected result:
       2.000000 0.000000 -1.000000 2.000000
       0.000000 3.000000  2.000000 3.000000
       0.000000 0.000000  1.333333 5.000000 */

    /* {{0, 3, 2, 3},
       {2, 0, -1, 2},
       {-2, -2, 1, 1}}; */


    /* Expected result:
       1.000000 -1.000000 1.000000 0.000000 1.000000
       0.000000 2.000000 0.000000 1.000000 0.000000
       0.000000 0.000000 1.000000 0.500000 -2.000000
       0.000000 0.000000 0.000000 -2.000000 3.000000 */

    /* {{0, 2, 0, 1, 0},
       {1, -1, 1, 0, 1},
       {1, 0, 2, 1, -1},
       {0, 1, 1,-1, 1}}; */

    Matrix matrix1 = ask_for_matrix();

    gaussian_elimination(matrix1.total_rows, matrix1.total_cols, matrix1.matrix);
    print_matrix(matrix1.total_rows, matrix1.total_cols, matrix1.matrix);

    return 0;
}
