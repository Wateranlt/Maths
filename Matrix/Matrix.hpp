#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Matrix
{
private:
    float **matrix;
    int weigth;
    int heigth;
public:
    template<size_t h, size_t w> Matrix(float (*array)[h][w]);
    ~Matrix();
};

#endif