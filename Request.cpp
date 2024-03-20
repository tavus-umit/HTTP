/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file for the Request class
*/

#include "Request.h"

// Default constructor for the Request class
Request :: Request()
{
    id = 0;
    priority = 0;
    requestTime = 0;
    processTime = 0;

}
// Destructor for the request class
Request :: ~Request(){}

// Constructs a request object with the desired values given as arguments
Request :: Request(int newId, int newPriority, int newRequestTime, int newProcessTime)
{
    id = newId;
    priority = newPriority;
    requestTime = newRequestTime;
    processTime = newProcessTime;
}

// Copy constructor for the request class
Request :: Request(const Request& copyRequest)
{
    id = copyRequest.id;
    priority = copyRequest.priority;
    requestTime = copyRequest.requestTime;
    processTime = copyRequest.processTime;
}




