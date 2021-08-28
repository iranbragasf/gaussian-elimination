#include <stdio.h>
#include <stdlib.h>
#include "gaussian_elimination.h"

Matrix create_matrix(const size_t total_rows, const size_t total_cols) {
    Matrix matrix;
    matrix.total_rows = total_rows;
    matrix.total_cols = total_cols;
    matrix.matrix = (double **) malloc(total_rows * sizeof(double *));

    for (size_t i = 0; i < total_rows; ++i)
        matrix.matrix[i] = (double *) malloc(total_cols * sizeof(double));

    for (size_t i = 0; i < total_rows; ++i) {
        if (i == 0)
            printf("Insert %lust row: ", i + 1);
        else if (i == 1)
            printf("Insert %lund row: ", i + 1);
        else if (i == 2)
            printf("Insert %lurd row: ", i + 1);
        else
            printf("Insert %luth row: ", i + 1);

        printf("\n");

        for (size_t j = 0; j < total_cols; ++j)
            scanf("%lf", *(matrix.matrix + i) + j);

        printf("\n");
    }

    return matrix;
}

Matrix ask_for_matrix() {
    size_t total_rows, total_cols;

    printf("Haw many rows has the matrix? ");
    scanf("%lu", &total_rows);

    printf("Haw many columns has the matrix? ");
    scanf("%lu", &total_cols);

    printf("\n");

    return create_matrix(total_rows, total_cols);
}
