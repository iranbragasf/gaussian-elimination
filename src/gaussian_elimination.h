#ifndef _GAUSSIAN_ELIMINATION_H
#define _GAUSSIAN_ELIMINATION_H

#include <stdio.h>

#define GET_ROWS(matrix) sizeof(matrix) / sizeof(matrix[0])
#define GET_COLS(matrix) sizeof(matrix[0]) / sizeof(matrix[0][0])

void gaussian_elimination(const size_t total_rows, const size_t total_cols, double **matrix);
void search(const size_t total_rows, const size_t total_cols, size_t *curr_row, size_t *curr_col, size_t *pivot, double **matrix);
void swap(const size_t total_rows, const size_t total_cols, size_t *curr_row, size_t *curr_col, size_t *pivot, double **matrix);
void elim(size_t total_rows, size_t total_cols, size_t *curr_row, size_t *curr_col, size_t *pivot, double **matrix);
void print_matrix(const size_t total_rows, const size_t total_cols, double **matrix);

typedef struct Matrix {
    size_t total_rows;
    size_t total_cols;
    double **matrix;
} Matrix;

#endif // _GAUSSIAN_ELIMINATION_H
