//File Test
#include "Matrix.hpp"
#include <Windows.h>

int main(int argc, char const *argv[])
{
    float array[2][3] = { {1, 2, 3}, {4, 5, 6}};
    Matrix matrix1(array);
    Sleep(5000);
    return 0;
}
