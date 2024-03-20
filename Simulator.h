/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Header file for the Simulator class
*/

#ifndef HTTP_SIMULATOR_H
#define HTTP_SIMULATOR_H
#include "ComputerLinkedList.h"
#include "RequestHeap.h"
#include <ctime>


class Simulator {
private:
    ComputerLinkedList* computers;
    RequestHeap* requests;
    int computerSize;
    double goalAvgTime;
    int sumWaitTime;
    int currentTime;
    string logFile;
public:
    Simulator(string newLogFile, double newGoalAvgTime);
    ~Simulator();
    void startSimulation();
    void ultimateSimulation();
    void processRequest(Request& processingRequest);
    void processRequestWithPrint(Request& processingRequest);
    bool isGoalAchieved();
    void updateComputers();
    void reserveRequests();
    void refillComputers();
    void resetSumWaitTime();
    void resetSimulation();
};


#endif //HTTP_SIMULATOR_H
