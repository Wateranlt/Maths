#include "Matrix.hpp"

template<size_t h, size_t w> 
Matrix::Matrix(float (*array)[h][w])
{
    matrix = new float*[h];
    for (size_t i = 0; i < h; i++)
    {
        matrix[i] = new float[j];
        for (size_t j = 0; j < w; i++)
        {
            matrix[i][j] = array[i][j];
        }
    }
    heigth = h, weigth = w;
}