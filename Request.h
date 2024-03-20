/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Header file for the Request class
*/

#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H
#include <iostream>
using namespace std;


class Request {
private:
    int id;
    int priority;
    int requestTime;
    int processTime;
public:
    Request();
    Request(int newId, int newPriority, int newRequestTime, int newProcessTime);
    Request(const Request& copyRequest);
    ~Request();

    friend class RequestHeap;
    friend class Simulator;

};


#endif //HTTP_REQUEST_H
