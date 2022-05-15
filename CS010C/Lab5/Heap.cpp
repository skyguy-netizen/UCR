#include "Heap.h"
#include <iostream>
// #include <cmath>

using namespace std;

Heap::Heap() : numItems(0) {}

void Heap::enqueue(PrintJob *job)
{
    if (numItems != MAX_HEAP_SIZE){
        if (empty()){
            arr[0] = job;
            numItems++;
        }
        else {
        arr[numItems] = job;
        numItems++;
        int Jobval = numItems - 1;
        while (job->getPriority() > arr[(Jobval - 1) / 2]->getPriority())
        {
            swap(Jobval, (Jobval - 1)/2);
            // arr[(Jobval - 1) / 2] = job;
            // arr[Jobval] = temp;
            // // std::swap(job, arr[(Jobval - 1) / 2]); //this doesn't work for some reason
            Jobval = (Jobval - 1) / 2;
        }
        }
    }
}

void Heap::dequeue() {
    if (!empty()){
        PrintJob *toDelete = arr[0];
        arr[0] = arr[numItems-1];
        delete toDelete;
        numItems--;
        trickleDown(0);
    }
}

PrintJob * Heap::highest(){
    if (!empty())
        return arr[0];
    return nullptr;
}

void Heap::print()
{
    if(!empty()){
        std::cout << "Priority: " << highest()->getPriority() << ", ";
        std::cout << "Job Number: " << highest()->getJobNumber() << ", ";
        std::cout << "Number of Pages: " << highest()->getPages() << std::endl;
    }
}

void Heap::trickleDown(int val)
{
    // if ((arr[val]->getPriority() > arr[val*2+1]->getPriority() && arr[val]->getPriority() > arr[val*2+2]->getPriority()) || val == numItems/2){
    //     return;
    // }
    if (numItems < val * 2 + 2){
        return;
    }
    else if (numItems == val*2 + 2){
        if (arr[val]->getPriority() > arr[val*2+2]->getPriority()){
            swap(val, val*2+2);
        }
    }
    else {
        if (arr[val*2+1]->getPriority() > arr[val*2+2]->getPriority()){
            if (arr[val*2+1]->getPriority() > arr[val]->getPriority()){
                swap(val, val*2+1);
                trickleDown(val*2+1);
            }
            else {
                return;
            }
        }
        else {
            if (arr[val*2+2]->getPriority() > arr[val]->getPriority()){
                swap(val, val*2+2);
                trickleDown(val*2+1);
            }
            else {
                return;
            }
        }
    }

}

bool Heap::empty(){
    return numItems == 0;
}

void Heap::swap(int i, int j){
    PrintJob* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
