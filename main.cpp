/*
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Main.cpp
*/
#include "Simulator.h"


int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <filename> <avgWaitingTime>" << endl;
        return 1;
    }

    string filename = argv[1];
    double avgWaitingTime = stod(argv[2]);

    Simulator simulator(filename, avgWaitingTime);
    simulator.startSimulation();
}
