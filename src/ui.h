#ifndef _UI_H
#define _UI_H

#include <stdio.h>
#include "gaussian_elimination.h"

Matrix create_matrix(const size_t total_rows, const size_t total_cols);
Matrix ask_for_matrix();

#endif //_UI_H
