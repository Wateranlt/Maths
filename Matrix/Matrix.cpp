#include "Matrix.hpp"
#include <iostream>

void Matrix::print() const
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            std::cout << matrix[i][j];
            std::cout << " "; 
        }
        std::cout << "\n";
    }
}

std::string Matrix::toString() const
{
    std::string output;
    output += "[";
    for (size_t i = 0; i < height; i++)
    {
        output += "{";
        for (size_t j = 0; j < width; j++)
        {
            output += std::to_string(matrix[i][j]);
            output += ","; 
        }
        output += "},";
    }
    output += "]";
    return output;
}