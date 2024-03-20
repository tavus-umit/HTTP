/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file for Simulator class.
*/

#include "Simulator.h"

// Constructor for Simulator class
Simulator::Simulator(string newLogFile, double newGoalAvgTime)
{
    requests = nullptr;
    computers = nullptr;
    logFile = newLogFile;
    goalAvgTime = newGoalAvgTime;
    computerSize = 1;
    resetSimulation();
}

// Destructor for Simulator class
Simulator::~Simulator() {
    delete requests;
    delete computers;
}


// Makes the simulation until the minimum number of computers is found for desired average wait time
void Simulator::startSimulation()
{
    bool isGoalTimeFound = false;
    while(!isGoalTimeFound)
    {
        reserveRequests();
        ifstream file(logFile);
        int requestAmount;
        file >> requestAmount;

        int logId;
        int logPriority;
        int logRequest;
        int logProcess;

        file >> logId;
        file >> logPriority;
        file >> logRequest;
        file >> logProcess;


        bool isSimulationFinished = false;
        while (!isSimulationFinished) {
            while (logRequest == currentTime && requestAmount != 0) {

                Request newRequest = Request(logId, logPriority, logRequest, logProcess);
                requests->insertHeap(newRequest);
                requestAmount--;

                file >> logId;
                file >> logPriority;
                file >> logRequest;
                file >> logProcess;

            }
            while (computers->isThereAvailableComputer() && !requests->isHeapEmpty()) {
                Request processedRequest = requests->peekMaxRequest();
                processRequest(processedRequest);
                requests->deleteRequest();
            }
            updateComputers();
            currentTime++;
            if (requests->isHeapEmpty() && requestAmount == 0) {
                isSimulationFinished = true;
            }

        }

        if(isGoalAchieved())
        {
            isGoalTimeFound = true;
            resetSimulation();
        }

        else
        {
            computerSize++;
            resetSimulation();
        }

    }
    ultimateSimulation();
}

// After the minimum number of computers is found in startSimulation(), one last simulation is done with the minimum number of computers to print the simulation result
void Simulator :: ultimateSimulation()
{
    cout << "Minimum number of computers required: " << computerSize << endl;
    cout << endl;
    cout << "Simulation with " << computerSize << " computers:" << endl;
    cout << endl;

    reserveRequests();
    ifstream file(logFile);
    int requestAmount;
    file >> requestAmount;

    int logId;
    int logPriority;
    int logRequest;
    int logProcess;

    file >> logId;
    file >> logPriority;
    file >> logRequest;
    file >> logProcess;


    bool isSimulationFinished = false;
    while (!isSimulationFinished) {

        while (logRequest == currentTime && requestAmount != 0) {


            Request newRequest = Request(logId, logPriority, logRequest, logProcess);
            requests->insertHeap(newRequest);
            requestAmount--;

            file >> logId;
            file >> logPriority;
            file >> logRequest;
            file >> logProcess;

        }
        while (computers->isThereAvailableComputer() && !requests->isHeapEmpty()) {
            Request processedRequest = requests->peekMaxRequest();
            processRequestWithPrint(processedRequest);
            requests->deleteRequest();
        }
        updateComputers();
        currentTime++;
        if (requests->isHeapEmpty() && requestAmount == 0) {
            isSimulationFinished = true;
        }

    }
    cout << endl;
    cout << "Average waiting time: ";
    double result = (double)sumWaitTime/requests->reservedHeapSize;
    printf("%.2lf", result);
    cout << " ms" << endl;
}

// Process the giving request by assigning it to the first available computer in computers which is a ComputerLinkedList
void Simulator::processRequest(Request& processingRequest)
{
    Computer* processor = computers->findAvailableComputer();
    processor->isAvailable = false;
    processor->coolDown = currentTime + processingRequest.processTime;
    int waitTime = (currentTime - processingRequest.requestTime);
    sumWaitTime = sumWaitTime + waitTime;
}

// Does the same process with processRequest() method. It just prints the process result
void Simulator::processRequestWithPrint(Request& processingRequest)
{
    Computer* processor = computers->findAvailableComputer();
    processor->isAvailable = false;
    processor->coolDown = currentTime + processingRequest.processTime;
    int waitTime = (currentTime - processingRequest.requestTime);
    sumWaitTime = sumWaitTime + waitTime;
    cout << "Computer " << processor-> id << " takes request " << processingRequest.id << " at ms " << currentTime << " (wait: " << waitTime << " ms)" << endl;
}

// Determine whether the average wait time reaches to the maximum value of smaller than goal average wait time value
bool Simulator::isGoalAchieved() {
    if((double)sumWaitTime/requests->reservedHeapSize < goalAvgTime)
        return true;

    else
        return false;
}

// Updates the computers by refreshing them via refreshComputers() method of ComputerLinkedList class
void Simulator::updateComputers()
{
    computers->refreshComputers(currentTime);
}

// Reconstructs the RequestHeap object into the requests data member
void Simulator::reserveRequests()
{
    ifstream file (logFile);
    int reservedSize = 0;
    if(file.is_open())
    {
        file >> reservedSize;
        if(requests == nullptr)
            requests = new RequestHeap(reservedSize);
        else
        {
            RequestHeap* deleteHeap = requests;
            requests = new RequestHeap(reservedSize);
            delete deleteHeap;
        }
    }
    file.close();
}

// Reconstructs the ComputerLinkedList object into the computers data member
void Simulator::refillComputers()
{
    Computer :: currentID = 0;
    if(computers == nullptr)
    {
        computers = new ComputerLinkedList(computerSize);
    }
    else
    {
        ComputerLinkedList* deleteComputers = computers;
        computers = new ComputerLinkedList(computerSize);
        delete deleteComputers;
    }
}

// Resets the total wait time
void Simulator::resetSumWaitTime() {
    sumWaitTime = 0;
}

// Resets the simulation
void Simulator::resetSimulation() {
    currentTime = 0;
    resetSumWaitTime();
    refillComputers();
}




