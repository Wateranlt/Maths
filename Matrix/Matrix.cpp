#include "Matrix.hpp"
#include <iostream>

void Matrix::print() const
{
    for (size_t h = 0; h < height; h++)
    {
        for (size_t w = 0; w < width; w++)
        {
            std::cout << matrix[h][w];
            std::cout << " "; 
        }
        std::cout << "\n";
    }
}

std::string Matrix::toString() const
{
    std::string output;
    output += "[";
    for (size_t h = 0; h < height; h++)
    {
        output += "{";
        for (size_t w = 0; w < width; w++)
        {
            output += std::to_string(matrix[h][w]);
            output += ","; 
        }
        output += "},";
    }
    output += "]";
    return output;
}

Matrix operator-(Matrix const& A)
{
    float **array;
    std::cout << A.getHeigth() << " and " << A.getWidth() << std::endl;
    array = new float*[A.getHeigth()];
    for(size_t h = 0 ; h < A.getHeigth() ; h++)
    {
        array[h] = new float[A.getWidth()];
        for(size_t w = 0; w < A.getWidth() ; w++)
        {
            array[h][w] = -A.matrix[h][w];
            std::cout << "number : " << array[h][w] << std::endl;
        }
    }
    return Matrix(array, 2, 3);
}

Matrix& Matrix::operator+=(Matrix const& A)
{
    for (size_t h = 0; h < height; h++)
    {
        for (size_t w = 0; w < width; w++)
        {
            matrix[h][w] += A.matrix[h][w];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(Matrix const& A)
{
    this->operator+=(-A);
    return *this;
}