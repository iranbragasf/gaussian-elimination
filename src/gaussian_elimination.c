#include <stdio.h>
#include "gaussian_elimination.h"

void gaussian_elimination(const int total_rows, const int total_cols, double (*matrix)[total_cols]) {
    int curr_row = 0, curr_col = 0, pivot = 0;

    search(total_rows, total_cols, &curr_row, &curr_col, &pivot, matrix);

    return;
}

void search(const int total_rows, const int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]) {
    if (matrix[*curr_row][*curr_col] == 0) {
        ++(*curr_row);

        if (*curr_row > total_rows - 1) {
            curr_row = pivot;
            ++(*curr_col);

            if (*curr_col > total_cols - 1)
                return;
        }

        search(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
    } else {
        // Check if the found pivot is on it's correct position
        if (*pivot == total_rows - 1)
            return;
        else {
            swap(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
        }
    }
}

void swap(const int total_rows, const int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]) {
    // Swap rows matrix[curr_row] and matrix[pivot]
    for (int j = 0; j < total_cols; ++j) {
        double tmp = matrix[*curr_row][j];
        matrix[*curr_row][j] = matrix[*pivot][j];
        matrix[*pivot][j] = tmp;
    }

    *curr_row = *pivot + 1;

    elim(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
}

void elim(const int total_rows, const int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]) {
    // Fill with 0 the elements below the pivot
    const double factor = - (double) matrix[*curr_row][*curr_col] / matrix[*pivot][*curr_col];

    // Replace matrix[curr_row] by matrix[curr_row] + fator * matrix[pivot]
    for (int j = 0; j < total_cols; ++j) {
        // if (*curr_row == total_rows - 2 && *curr_col == total_cols - 2)
        // printf("element: %f | factor * previous element: %f\n", matrix[*curr_row][j], factor * matrix[*pivot][j]);

        matrix[*curr_row][j] = matrix[*curr_row][j] + factor * matrix[*pivot][j];
    }

    ++(*curr_row);

    if (*curr_row > total_rows - 1) {
        ++(*curr_col);

        if (*curr_col > total_cols - 1)
            return;

        ++(*pivot);
        *curr_row = *pivot;

        search(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
    } else {
        // Recursively replace matrix[curr_row] by matrix[curr_row] + fator * matrix[pivot]
        elim(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
    }

}
