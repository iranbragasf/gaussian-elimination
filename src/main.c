#include <stdio.h>
#include "gaussian_elimination.h"

int main() {
    double matrix1[][4] = {{0, 3, 2, 3},
                          {2, 0, -1, 2},
                          {-2, -2, 1, 1}};

    /* double matrix2[][5] = {{0, 2, 0, 1, 0},
                           {1, -1, 1, 0, 1},
                           {1, 0, 2, 1, -1},
                           {0, 1, 1,-1, 1}}; */

    gaussian_elimination(GET_ROWS(matrix1), GET_COLS(matrix1), matrix1);
    print_matrix(GET_ROWS(matrix1), GET_COLS(matrix1), matrix1);

    return 0;
}

void print_matrix(const int total_rows, const int total_cols, double (*matrix)[total_cols]) {
    for (int i = 0; i < total_rows; ++i) {
        for (int j = 0; j < total_cols; ++j) {
            printf("%f ", matrix[i][j]);
        }

        printf("\n");
    }
}
