#include <iostream>
#include "Heap.h"

using namespace std;

int menu()
{
    int choice = 0;
    std::cout << std::endl
              << "Enter menu choice: ";
    std::cout << std::endl;
    std::cout
        << "1. Enqueue" << std::endl
        << "2. Print" << std::endl
        << "3. Dequeue" << std::endl
        << "4. Quit" << std::endl;
    std::cin >> choice;

    // fix buffer just in case non-numeric choice entered
    // also gets rid of newline character
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return choice;
}

int main()
{
    Heap max_heap;

    int choice = menu();

    while (choice != 4)
    {

        if (choice == 1)
        {
            int priority, jobNumber, numPages;
            std::cout << "Enter print job to enqueue (priority, job Number, number of pages): ";
            std::cin >> priority >> jobNumber >> numPages;
            std::cout << std::endl;

            max_heap.enqueue(new PrintJob(priority, jobNumber, numPages));
        }
        else if (choice == 2)
        {
            max_heap.print();
        }
        else if (choice == 3)
        {
            max_heap.dequeue();
        }
        // fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}
