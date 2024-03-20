/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Header file for the ComputerLinkedList class. ComputerLinkedList is a linked list class that holds computers as elements.
*/
#ifndef HTTP_COMPUTERLINKEDLIST_H
#define HTTP_COMPUTERLINKEDLIST_H
#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;



class ComputerLinkedList {

public:
    ComputerLinkedList();
    ComputerLinkedList(int newReservedSize);
    ComputerLinkedList& operator=(const ComputerLinkedList& right);
    ~ComputerLinkedList();
    bool isListEmpty();
    void deleteFirstComputer();
    void insertComputer();
    void refreshComputers(int currentTime);
    Computer* findAvailableComputer();
    bool isThereAvailableComputer();
private:
    int size;
    int reservedSize;
    Computer* headPtr;

    friend class Simulator;
};


#endif //HTTP_COMPUTERLINKEDLIST_H
