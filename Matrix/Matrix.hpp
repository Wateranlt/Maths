#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Matrix
{
private:
    float **matrix;
    int weigth;
    int heigth;
public:
    Matrix(int w, int h, float **matrix);
    ~Matrix();
};

#endif