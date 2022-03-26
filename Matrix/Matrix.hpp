#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <string>

class Matrix
{
private:
    float **matrix;
    int width;
    int height;
public:
    template <typename Array> 
    Matrix(Array& array) 
    {
        height = sizeof(array)/sizeof(array[0]), width = sizeof(array[0])/sizeof(array[0][0]);
        matrix = new float*[height];
        for (size_t i = 0; i < height; i++)
        {
            matrix[i] = new float[width];
            for (size_t j = 0; j < width; j++)
            {
                matrix[i][j] = array[i][j];
            }
        }
    }
    void print() const;
    std::string toString() const;
    int getwidth() const { return width; };
    int getHeigth() const { return height; };
    float getComponent(int line, int column) const { return matrix[line - 1][column - 1]; };
};

#endif