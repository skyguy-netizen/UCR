#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// PART 1
template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned minIndex = index;
    for (unsigned i = index + 1; i < vals.size(); i++)
    {
        // cout << "Inside if " << endl;
        if (vals[i] < vals[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

template <typename T>
void selection_sort(vector<T> &vals)
{
    if (vals.size() == 0)
        return;
    for (unsigned i = 0; i < vals.size() - 1; i++)
    {

        int minIndex = min_index(vals, i + 1);
        if (vals[minIndex] < vals[i])
        {
            T temp = vals[i];
            vals[i] = vals[minIndex];
            vals[minIndex] = temp;
        }
        /// printVector(vals);
    }
}

template <typename T>
void printVector(vector<T> &vals)
{
    if (vals.size() == 0)
        return;
    for (unsigned i = 0; i < vals.size(); i++)
    {
        cout << vals[i] << " ";
    }
    cout << endl;
}

// PART 2
// given code
vector<char> createVector()
{
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for (int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T>
T getElement(vector<T> vals, int index)
{
    return vals[index];
}

int main()
{

    // PART 1 TEST HARNESSES
    //  vector<int> vals;
    //  vals.push_back(1);
    //  vals.push_back(2);
    //  vals.push_back(3);
    //  vals.push_back(2);
    //  vals.push_back(1);
    //  // char dummyInput;
    //  //  testing min_index function
    //  //   cout << min_index(vals, 0) << endl;

    // // testing with int vector
    // cout << "Selection sorting int vector:" << endl;
    // selection_sort(vals);
    // cout << "Test" << endl;
    // printVector(vals);

    // // cin >> dummyInput;

    // // testing with char vector
    // vector<char> vals2;
    // selection_sort(vals2);
    // cout << "Selection sorting char vector:" << endl;
    // printVector(vals2);

    // // testing with string vector
    // vector<string> vals3;
    // selection_sort(vals3);
    // cout << "Selection sorting string vector:" << endl;
    // printVector(vals3);

    // PART 2

    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while (--numOfRuns >= 0)
    {
        cout << "Enter a number: " << endl;
        cin >> index;
        try
        {
            if (index >= static_cast<int>(vals.size()) || index < 0)
            {
                throw std::out_of_range("out of range exception occured");
            }
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (std::out_of_range &err)
        {
            cout << err.what() << endl;
            // cout << "out of range exception occured" << endl;
            exit(0);
        }
    }

    return 0;
}
