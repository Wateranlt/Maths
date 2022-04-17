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
    template <typename Array = float> 
    Matrix(int h, int w, Array const& array) 
    {
        height = h, width = w;
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
    //Empty matrix used as error value in function 
    Matrix(int o)
    {
        matrix = nullptr;
        height = o, width = o;
    }

    void print() const;
    std::string toString() const;
    int getWidth() const { return width; };
    int getHeigth() const { return height; };
    float getComponent(int line, int column) const { return matrix[line - 1][column - 1]; };
    Matrix IdentityMatrix();
    //Operators
    Matrix& operator+=(Matrix const& A);
    Matrix& operator-=(Matrix const& A);
    Matrix& operator*=(Matrix const& A);
    
    friend Matrix operator+(Matrix const& A, Matrix const& B);
    friend Matrix operator-(Matrix const& A, Matrix const& B);
    friend Matrix operator-(Matrix const& A);
    friend Matrix operator*(Matrix const& A, Matrix const& B);
};

#endif