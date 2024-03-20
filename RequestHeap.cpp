/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file that includes the implementations of the member function of the Request Heap class. Request heap is the class of array based implementation of heap data
 * structure for request objects. It's a maxheap as the heap rebuilds according to the biggest priority of the request, however when there are multiple biggest priorities, the maximum heap element will
 * be the one that has the smallest request time, and when there are multiple smallest request times, then the maximum element will be the one has the smallest id.
*/

#include "RequestHeap.h"

// Default constructor of RequestHeap class
RequestHeap::RequestHeap() {
    reservedHeapSize = 0;
    currentHeapSize = 0;
    requests = nullptr;
}

// Constructor of RequestHeap class that allocates the request elements dynamically according to the number of allocations given as argument of reservedSize
RequestHeap::RequestHeap(int reservedSize) {

    reservedHeapSize = reservedSize;
    currentHeapSize = 0;
    requests = new Request [reservedHeapSize];
}

// Destructor of RequestHeap class that deallocates the request elements after its job is done
RequestHeap::~RequestHeap() {
    delete [] requests;
}

// Checks whether the heap is empty or not and returns boolean value
bool RequestHeap::isHeapEmpty() {
    if(currentHeapSize == 0)
        return true;
    else
        return false;
}


// Deletes the maximum request element of the RequestHeap
void RequestHeap::deleteRequest()
{
    Request deleteRequest = requests[0];
    requests[0] = requests[currentHeapSize - 1];
    requests[currentHeapSize - 1] = deleteRequest;
    currentHeapSize--;
    heapRebuild(0);
}

// A recursion method that rebuilds the RequestHeap according to the request that has the biggest priority
void RequestHeap::heapRebuild(int rootIndex)
{
    int maxIndex = rootIndex;
    int leftChild = 2*rootIndex+1;
    int rightChild = leftChild + 1;
    if(leftChild < currentHeapSize && requests[leftChild].priority > requests[rootIndex].priority)
    {
        maxIndex = leftChild;
    }
    else if (leftChild < currentHeapSize && requests[leftChild].priority == requests[rootIndex].priority)
    {
        maxIndex = heapRebuildRequestTime(maxIndex);
    }
    if(rightChild < currentHeapSize && requests[rightChild].priority > requests[maxIndex].priority)
    {
        maxIndex = rightChild;
    }
    else if (rightChild < currentHeapSize && requests[rightChild].priority == requests[maxIndex].priority)
    {
        maxIndex = heapRebuildRequestTime(maxIndex);
    }
    if(maxIndex != rootIndex)
    {
        Request temp = requests[maxIndex];
        requests[maxIndex] = requests[rootIndex];
        requests[rootIndex] = temp;
        heapRebuild(maxIndex);
    }
}

// Helper method for heapRebuild method and it's in use when they are multiple requests that have the biggest priorities
// It determines which request will be maximum element according to the smallest request time
// It returns the index of the request that has the smallest request time among the requests having the biggest priority
int RequestHeap::heapRebuildRequestTime(int rootIndex)
{
    int minIndex = rootIndex;
    int leftChild = 2*rootIndex+1;
    int rightChild = leftChild + 1;
    if(leftChild < currentHeapSize && requests[leftChild].requestTime < requests[rootIndex].requestTime)
    {
        minIndex = leftChild;
    }
    else if (leftChild < currentHeapSize && requests[leftChild].requestTime == requests[rootIndex].requestTime)
    {
        minIndex = heapRebuildID(minIndex);
    }
    if(rightChild < currentHeapSize && requests[rightChild].requestTime < requests[minIndex].requestTime)
    {
        minIndex = rightChild;
    }
    else if (rightChild < currentHeapSize && requests[rightChild].requestTime == requests[minIndex].requestTime)
    {
        minIndex = heapRebuildID(minIndex);
    }
    return minIndex;
}

// Helper method for heapRebuild method like heapRebuildRequestTime, and it's in use when they are multiple requests that have the biggest priorities, and also the smallest request times
// It determines which request will be maximum element according to the smallest id
// It returns the index of the request that has the smallest rid among the requests having the biggest priority and the smallest request time simultaneously
int RequestHeap::heapRebuildID(int rootIndex)
{
    int minIndex = rootIndex;
    int leftChild = 2*rootIndex+1;
    int rightChild = leftChild + 1;
    if(leftChild < currentHeapSize && requests[leftChild].id < requests[rootIndex].id)
    {
        minIndex = leftChild;
    }
    if(rightChild < currentHeapSize && requests[rightChild].id < requests[minIndex].id)
    {
        minIndex = rightChild;
    }
    return minIndex;
}

// Deletes the all elements of the RequestHeap
void RequestHeap::deleteHeap() {
    while(currentHeapSize > 0)
        deleteRequest();
}

// Returns the maximum request element of the RequestHeap
Request& RequestHeap::peekMaxRequest()
{
    return requests[0];
}

// Inserts the given request as argument into the RequetHeap
void RequestHeap::insertHeap(const Request &insertRequest) {

        requests[currentHeapSize] = insertRequest;

        int place = currentHeapSize;
        int parent = (place - 1)/2;
        while((place > 0) && (requests[place].priority > requests[parent].priority))
        {
            Request temp = requests[parent];
            requests[parent] = requests[place];
            requests[place] = temp;
            place = parent;
            parent = (place - 1)/2;
        }
        heapRebuild(0);
        currentHeapSize++;
}







