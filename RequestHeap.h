/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Header file for the Request Heap class. Request heap is the class of array based implementation of heap data
 * structure for request objects. It's a maxheap as the heap rebuilds according to the biggest priority of the request, however when there are multiple biggest priorities, the maximum heap element will
 * be the one that has the smallest request time, and when there are multiple smallest request times, then the maximum element will be the one has the smallest id.
*/

#ifndef HTTP_REQUESTHEAP_H
#define HTTP_REQUESTHEAP_H
#include "Request.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class RequestHeap {
public:
    RequestHeap();
    RequestHeap(int reservedSize);
    ~RequestHeap();
    bool isHeapEmpty();
    void insertHeap(const Request& insertRequest);
    void deleteHeap();
    void deleteRequest();
    void heapRebuild(int rootIndex);
    int heapRebuildRequestTime(int rootIndex);
    int heapRebuildID(int rootIndex);
    Request& peekMaxRequest();
private:
    Request* requests;
    int currentHeapSize;
    int reservedHeapSize;

    friend class Simulator;
};


#endif //HTTP_REQUESTHEAP_H
