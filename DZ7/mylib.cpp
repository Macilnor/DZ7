#include <iostream>
#include "mylib.h"


//Exercise 7.1/7.5
namespace MyLib
{
    float* initArray(size_t size)
    {
        float* ptArr = nullptr;

        if (size > 0)
        {
            ptArr = new (std::nothrow) float[size];

            if (ptArr != nullptr)
            {
                for (size_t i = 0; i < size; i++)
                {
                    std::cout << "Enter " << i << " value: ";
                    float a;
                    std::cin >> a;
                    ptArr[i] = a;
                }
            }
        }

        return ptArr;
    }

    void printArray(float* arr, size_t size)
    {
        std::cout << "[ ";
        for (size_t i = 0; i < size; i++)
        {
            std::string end = (i == size - 1) ? " ]" : " , ";
            std::cout << arr[i] << end;
        }
        std::cout << std::endl;
    }

    void countPosNeg(float* arr, size_t size)
    {
        int neg = 0;
        int pos = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] < 0)
            {
                neg++;
            }
            else if (arr[i] > 0)
            {
                pos++;
            }
        }
        std::cout << "Negative elements: " << neg << " ||Positive elements: " << pos << std::endl;
    }
}