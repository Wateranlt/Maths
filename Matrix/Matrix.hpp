#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Matrix
{
private:
    float **matrix;
    int weigth;
    int heigth;
public:
    template <typename Array> 
    Matrix(Array& array) 
    {
        heigth = sizeof(array)/sizeof(array[0]), weigth = sizeof(array[0])/sizeof(array[0][0]);
        matrix = new float*[heigth];
        for (size_t i = 0; i < heigth; i++)
        {
            matrix[i] = new float[weigth];
            for (size_t j = 0; j < weigth; j++)
            {
                matrix[i][j] = array[i][j];
            }
        }
    }
};

#endif