#include <iostream>

using namespace std;
#include <ctime>

#include "minFunc.h"

int main()
{
   srand(time(0));
   int arrSize;
   cin >> arrSize;
   if (arrSize > 0)
   {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i)
      {
         arr[i] = rand() % 6;
         cout << arr[i] << endl;
      }
      cout << "Test1" << endl;
      // cout << "Test1" << endl;
      const int *minLoc = min(arr, arrSize);
      // cout << "Test2" << endl;
      cout << "Min: " << *minLoc << endl;
   }
   return 0;
}
