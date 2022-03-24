#include "Matrix.hpp"

Matrix::Matrix(int h, int w, float **matrix)
{
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; i++)
        {
            Matrix::matrix[i][j] = matrix[i][j];
        }
        
    }
    heigth = h, weigth = w;
}