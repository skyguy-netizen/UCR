#include "minFunc.h"
#include <iostream>

using namespace std;

const int *min(const int arr[], int arrSize)
{
    // const int *minVal;
    // cout << "Size: " << arrSize << endl;
    if (arrSize <= 0)
    {
        return nullptr;
    }
    else if (arrSize == 1)
    {
        // cout << *arr << endl;
        return arr;
    }
    // else if (arrSize == 2)
    // {
    //     if (arr[0] < arr[1])
    //     {
    //         return arr;
    //     }
    //     else
    //     {
    //         return arr + 1;
    //     }
    // }
    // else if (arrSize == 2)
    // {
    //     minVal = arr + 1;
    // }
    else
    {
        // if (arr[arrSize - 1] < arr[arrSize - 2])
        // {
        //     return (arr + arrSize - 1);
        // }
        // else if (arr[arrSize - 2] < arr[arrSize - 1])
        // {
        //     return (arr + arrSize - 2);
        // }
        // else
        // {
        //     const int *minIndex = min(arr, arrSize - 1);
        //     return minIndex;
        // }
        // const int *last = (arr + arrSize - 1);
        // if (arrSize > 0)
        // {
        const int *minVal = min(arr + 1, arrSize - 1);
        if (arr[0] < *minVal)
        {
            // cout << *arr << endl;
            return arr;
        }
        else
        {
            return minVal;
        }

        // else
        // {
        //     return nullptr;
        // }
        // if (*(arr + (arrSize - 1)) < *min(arr, arrSize - 1))
        // {
        //     minVal = arr + (arrSize - 1);
        // }
        // else
        // {
        //     minVal = min(arr + 1, arrSize - 1);
        // }
    }
}