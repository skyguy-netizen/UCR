#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}


//Quicksort_midpoint Implementation
int partition_midpoint (int numbers[], int, int);

void Quicksort_midpoint(int numbers[], int i, int k){
  if (i >= k){
    return;
  }
  int invariant = partition_midpoint(numbers, i, k);
  Quicksort_midpoint(numbers, i, invariant);
  Quicksort_midpoint(numbers, invariant + 1, k);
}

int partition_midpoint(int numbers[], int i, int j){
  int midpoint = i + (j - i)/2;
  int pivot = numbers[midpoint];
  bool done = false;
  while (!done) {
    while (numbers[i] < pivot){
      i++;
    }

    while (numbers[j] > pivot){
      j--;
    }
    if (i >= j){
      done = true;
    }
    else {
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;

      i++;
      j--;
    }
  }
  return j;
}




//Quicksort_medianOfThree Implementation
int partition_medianOfThree(int numbers[], int i, int j);
int medianOfThree(int, int, int);

void Quicksort_medianOfThree(int numbers[], int i, int k){
  if (i >= k){
    return;
  }
  int invariant = partition_medianOfThree(numbers, i, k);
  Quicksort_midpoint(numbers, i, invariant);
  Quicksort_midpoint(numbers, invariant + 1, k);
}

int partition_medianOfThree(int numbers[], int i, int j){
  int pivot = numbers[medianOfThree(numbers[i], numbers[j], numbers[i + (j-i)/2])];
  bool done = false;
  while (!done) {
    while (numbers[i] < pivot){
      i++;
    }

    while (numbers[j] > pivot){
      j--;
    }
    if (i >= j){
      done = true;
    }
    else {
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;

      i++;
      j--;
    }
  }
  return j;
}

int medianOfThree(int a, int b, int c){
  if ((a > b) && (a > c)){
    return a;
  }
  else if ((b > a) && (b > c)){
    return b;
  }
  else {
    return c;
  }
}


//Insertion Sort Implementation
void InsertionSort(int arr[], int size){
  for (int i = 0; i < size; i++){
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}


//Helper function to print elements in an arrays
void print(int numbers[], int size){
  for (int i = 0; i < size; i++){
    cout << numbers[i] << " ";
  }
  cout << endl;
}





int main(){
  //const int CLOCKS_PER_MS = CLOCKS_PER_SEC/100;
  //clock t_start = clock();
  int arr1[NUMBERS_SIZE], arr2[NUMBERS_SIZE], arr3[NUMBERS_SIZE];
  fillArrays(arr1, arr2, arr3);
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
  print(arr1, NUMBERS_SIZE);
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
  print(arr2, NUMBERS_SIZE);
  InsertionSort(arr3, NUMBERS_SIZE);
  print(arr3, NUMBERS_SIZE);
  return 0;
}
