//File Test
//Command : g++ -g *.cpp -o MatrixTest.exe
#include "Matrix.hpp"
#include <Windows.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    float array1[2][3] = { {1, 2, 3}, {4, 5, 6}}, array2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    Matrix matrix1(2, 3, array1), matrix2(3, 2, array2);
    matrix1.print();
    std::cout << "Number with index (2,2) : " << matrix1.getComponent(2, 2) << std::endl;
    Matrix matrix3 = matrix1 * matrix2;
    std::cout << matrix3.toString();
    matrix3 -= matrix1;
    matrix3.print();
    Sleep(3000);
    return 0;
}
