/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file for the Request class
*/

#ifndef HTTP_COMPUTER_H
#define HTTP_COMPUTER_H
#include <iostream>
using namespace std;


class Computer {

private:
        bool isAvailable;
        int id;
        int coolDown;
        Computer* nextPtr;
public:
        static int currentID;
        Computer();
        Computer& operator=(const Computer& right);
        ~Computer();


        friend class ComputerLinkedList;
        friend class Simulator;
};




#endif //HTTP_COMPUTER_H
