#include <iostream>
#include <fstream>

using namespace std;

bool rCopy(const string &file1, const string &file2);

ofstream &rCopyHelper(ifstream &fin, ofstream &fout);
int counter = 0;

int main(int argc, char *argv[])
{
    string file1;
    string file2;
    // cout << "Enter file1 name: ";
    // cin >> file1;
    // cout << "Enter file2 name: ";
    // cin >> file2;
    // cout << "Test" << endl;
    file1 = argv[1];
    file2 = argv[2];
    if (rCopy(file1, file2))
    {
        cout << "Contents have been copied" << endl;
    }
    cout << "Recursions: " << counter << endl;
    return 0;
}

bool rCopy(const string &file1, const string &file2)
{
    // cout << "In rCopy" << endl;
    ifstream fin(file1);
    if (!fin.is_open())
    {
        cout << "Error opening " << file1 << endl;
        cout << "Copy not completed" << endl;
        return false;
    }
    ofstream fout(file2);
    // cout << "Testing streams" << endl;
    if (!fout.is_open())
    {
        cout << "Error opening " << file1 << endl;
        cout << "Copy not completed" << endl;
        return false;
    }
    // if (!fin.is_open() || !fout.is_open())
    // {
    //     return false;
    // }

    rCopyHelper(fin, fout);
    fin.close();
    fout.close();
    return true;
}

ofstream &rCopyHelper(ifstream &fin, ofstream &fout)
{
    // cout << "Helper function test" << endl;
    char ch;
    if (fin.get(ch))
    {
        // cout << "Character read in: " << ch << endl;
        rCopyHelper(fin, fout);
        fout << ch;
    }

    counter++;
    return fout;
}