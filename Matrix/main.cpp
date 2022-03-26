//File Test
//Command : g++ -g *.cpp -o MatrixTest.exe
#include "Matrix.hpp"
#include <Windows.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    float array[2][3] = { {1, 2, 3}, {4, 5, 6}};
    Matrix matrix1(array);
    matrix1.print();
    std::cout << "Number with index (2,2) : " << matrix1.getComponent(2, 2);
    Sleep(3000);
    return 0;
}
