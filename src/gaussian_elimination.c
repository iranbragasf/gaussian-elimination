#include <stdio.h>
#include "gaussian_elimination.h"

void gaussian_elimination(const size_t total_rows, const size_t total_cols, double **matrix) {
    size_t curr_row = 0, curr_col = 0, pivot = 0;

    search(total_rows, total_cols, &curr_row, &curr_col, &pivot, matrix);

    return;
}

void search(const size_t total_rows,
        const size_t total_cols,
        size_t *curr_row,
        size_t *curr_col,
        size_t *pivot,
        double **matrix) {
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

void swap(const size_t total_rows,
        const size_t total_cols,
        size_t *curr_row,
        size_t *curr_col,
        size_t *pivot,
        double **matrix) {
    // Swap rows matrix[curr_row] and matrix[pivot]
    for (size_t j = 0; j < total_cols; ++j) {
        double tmp = matrix[*curr_row][j];
        matrix[*curr_row][j] = matrix[*pivot][j];
        matrix[*pivot][j] = tmp;
    }

    *curr_row = *pivot + 1;

    elim(total_rows, total_cols, curr_row, curr_col, pivot, matrix);
}

void elim(const size_t total_rows,
        const size_t total_cols,
        size_t *curr_row,
        size_t *curr_col,
        size_t *pivot,
        double **matrix) {
    // Fill with 0 the elements below the pivot
    const double factor = - (double) matrix[*curr_row][*curr_col] / matrix[*pivot][*curr_col];

    // Replace matrix[curr_row] by matrix[curr_row] + fator * matrix[pivot]
    for (size_t j = 0; j < total_cols; ++j) {
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

void print_matrix(const size_t total_rows, const size_t total_cols, double **matrix) {
    for (size_t i = 0; i < total_rows; ++i) {
        for (size_t j = 0; j < total_cols; ++j) {
            if (j == total_cols - 1) {
                printf("%f\n", matrix[i][j]);
                break;
            }

            printf("%f ", matrix[i][j]);
        }
    }
}
