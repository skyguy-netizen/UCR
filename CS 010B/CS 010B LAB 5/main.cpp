// include any standard libraries needed
#include <iostream>
#include <fstream>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);

const int ARR_CAP = 100;

int main(int argc, char *argv[])
{

    ifstream fin;
    string filename;
    int indexToRemove = 0;
    // int arrSize = 0;
    string space;
    // int cnt = 0;
    // verify file name provided on command line
    if (argc != 2)
    {
        cout << "Usage: main.cpp sample.txt" << endl;
        exit(1);
    }

    filename = argv[1];
    // open file and verify it opened
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    // Declare an array of doubles of size ARR_CAP.
    double arr[ARR_CAP];

    // cout << arr[99] << endl;
    // return 0;
    // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    double input;
    int arrSize = 0;
    while (fin >> arr[arrSize])
    {
        // arr[i] = input;
        //  fin >> space;
        //  cout << arr[i] << " ";
        // i++;
        arrSize++;
    }
    // for (int i = 0; i < ARR_CAP; i++)
    // {
    //    cout << arr[i] << endl;
    // }
    // return 0;
    // cout << cnt << endl;
    // cout << arr[98] << endl;
    //  Call the mean function passing it this array and output the
    //  value returned.

    cout << "Mean: " << mean(arr, arrSize) << endl;

    // Ask the user for the index (0 to size - 1) of the value they want to remove.
    cout << "Enter index of value to be removed (0 to " << arrSize - 1 << "):";
    cin >> indexToRemove;
    cout << endl;

    // Call the display function to output the array.
    cout << "Before removing value: ";
    display(arr, arrSize);

    // Call the remove function to remove the value at the index
    // provided by the user.
    remove(arr, arrSize, indexToRemove);

    // Call the display function again to output the array
    // with the value removed.
    cout << "After removing value: ";
    display(arr, arrSize);
    // Call the mean function again to get the new mean

    cout << "Mean: " << mean(arr, arrSize) << endl;

    return 0;
}

double mean(const double array[], int arraySize)
{
    double sum = 0;

    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    return sum / arraySize;
}

void remove(double array[], int &arraySize, int index)
{
    int i;
    for (i = index; i + 1 < arraySize; i++)
    {
        array[i] = array[i + 1];
    }

    arraySize--;
}

void display(const double array[], int arraySize)
{
    int i = 0;
    for (i = 0; i + 1 < arraySize; i++)
    {
        cout << array[i] << ", ";
    }

    cout << array[i] << endl;
}
