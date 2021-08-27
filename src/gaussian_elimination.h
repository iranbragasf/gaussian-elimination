#ifndef _GAUSSIAN_ELIMINATION_H
#define _GAUSSIAN_ELIMINATION_H

#define GET_ROWS(matrix) sizeof(matrix) / sizeof(matrix[0])
#define GET_COLS(matrix) sizeof(matrix[0]) / sizeof(matrix[0][0])

void gaussian_elimination(const int total_rows, const int total_cols, double (*matrix)[total_cols]);
void search(const int total_rows, const int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]);
void swap(const int total_rows, const int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]);
void elim(int total_rows, int total_cols, int *curr_row, int *curr_col, int *pivot, double (*matrix)[total_cols]);
void print_matrix(const int total_rows, const int total_cols, double (*matrix)[total_cols]);

#endif // _GAUSSIAN_ELIMINATION_H
