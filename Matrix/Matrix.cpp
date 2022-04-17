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
            if(w + 1 < width)
                output += ","; 
        }
        output += "}";
        if(h + 1 < height)
            output += ",";
    }
    output += "]";
    return output;
}

Matrix operator-(Matrix const& A)
{
    float **array;
    array = new float*[A.getHeigth()];
    for(size_t h = 0 ; h < A.getHeigth() ; h++)
    {
        array[h] = new float[A.getWidth()];
        for(size_t w = 0; w < A.getWidth() ; w++)
        {
            array[h][w] = -A.matrix[h][w];
        }
    }
    return Matrix(A.getHeigth(), A.getWidth(), array);
}

Matrix& Matrix::operator+=(Matrix const& A)
{
    *this = *this + A;
    return *this;
}

Matrix& Matrix::operator-=(Matrix const& A)
{
    this->operator+=(-A);
    return *this;
}

Matrix operator*(Matrix const& A, Matrix const& B)
{
    if(A.getWidth() != B.getHeigth())
        return Matrix(0);
    
    float **matrix = new float*[A.getHeigth()];
    for(size_t i = 0 ; i < A.getHeigth(); i++)
    {
        matrix[i] = new float[B.getWidth()];
        for(size_t j = 0 ; j < B.getWidth() ; j++)
        {
            matrix[i][j] = 0;
            for (size_t k = 0; k < B.getHeigth(); k++)
            {
                matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
            }     
        }
    }
    return Matrix(A.getHeigth(), B.getWidth(), matrix);
}

Matrix operator+(Matrix const& A, Matrix const& B)
{
    if(A.getHeigth() != B.getHeigth() || A.getWidth() != B.getWidth())
        return Matrix(0);

    float **matrix = new float*[A.getHeigth()];
    for (size_t i = 0; i < A.getHeigth(); i++)
    {
        matrix[i] = new float[A.getWidth()];
        for (size_t j = 0; j < A.getWidth(); j++)
        {
            matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
    return Matrix(A.getHeigth(), A.getWidth(), matrix);    
}

Matrix operator-(Matrix const& A, Matrix const& B)
{
    return A + (-B);
}

Matrix& Matrix::operator*=(Matrix const& A)
{
    *this = *this * A;
    return *this;
}

Matrix Matrix::IdentityMatrix()
{
    float **matrix = new float*[height];
    for (size_t i = 0; i < height; i++)
    {
        matrix[i] = new float[width];
        for (size_t j = 0; j < width; j++)
        {
            if(i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    return Matrix(height, width, matrix);
}