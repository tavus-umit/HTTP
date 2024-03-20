/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file for the ComputerLinkedList class. ComputerLinkedList is a linked list class that holds computers as elements.
*/

#include "ComputerLinkedList.h"

// Default constructor for ComputerLinkedList
ComputerLinkedList::ComputerLinkedList()
{
    headPtr = nullptr;
    size = 0;
    reservedSize = -1;
}

// Constructor that creates desired number which is given as an argument of computers into the ComputerLinkedList
ComputerLinkedList::ComputerLinkedList(int newReservedSize)
{
    headPtr = nullptr;
    size = 0;
    reservedSize = newReservedSize;
    for (int i = 0; i < newReservedSize ; i++)
    {
        insertComputer();
        size++;
    }
}

// = operator overload to construct new ComputerLinkedList into an initialized data member
ComputerLinkedList &ComputerLinkedList::operator=(const ComputerLinkedList &right) {

    if(&right != this)
    {
        size = right.size;
        reservedSize = right.reservedSize;
        headPtr = nullptr;
        if(size > 0)
        {
            Computer* curRightPtr = right.headPtr;
            Computer* newComputer = new Computer();
            *newComputer = *curRightPtr;
            headPtr = newComputer;
            Computer* curPtr = headPtr;
            curRightPtr = curRightPtr -> nextPtr;
            while(curRightPtr != nullptr)
            {
                newComputer = new Computer();
                *newComputer = *curRightPtr;
                curPtr->nextPtr = newComputer;
                curPtr = curPtr -> nextPtr;
                curRightPtr = curRightPtr -> nextPtr;

            }

        }
    }
    return *this;
}

// Destructor for the ComputerLinkedList
ComputerLinkedList::~ComputerLinkedList()
{
    for (int i = 0; i < size; i++) {
        deleteFirstComputer();
    }
}

// Checks whether the ComputerLinkedList is empty or not
bool ComputerLinkedList::isListEmpty() {
    if(headPtr == nullptr)
        return true;
    else
        return false;
}

// Deletes the first computer of the ComputerLinkedList
void ComputerLinkedList::deleteFirstComputer() {

    Computer* deleteComputer = headPtr;
    headPtr = headPtr->nextPtr;
    deleteComputer->nextPtr = nullptr;
    delete deleteComputer;
    size--;
}

// Inserts a computer into a ComputerLinkedList
void ComputerLinkedList::insertComputer()
{
    if(isListEmpty())
    {
        Computer* newComputer = new Computer();
        headPtr = newComputer;
        size++;
    }
    else
    {
        Computer* prevPtr = nullptr;
        Computer* curPtr = headPtr;
        while(curPtr != nullptr)
        {
            prevPtr = curPtr;
            curPtr = curPtr->nextPtr;
        }
        Computer* newComputer = new Computer();
        curPtr = newComputer;
        prevPtr->nextPtr = curPtr;
        size++;
    }
}

// Refreshes the computers by setting inavailable computers to available and resetting their cooldown when the time comes according to the currentTime values given as argument
void ComputerLinkedList::refreshComputers(int currentTime)
{
    Computer* curPtr = headPtr;

    while(curPtr != nullptr)
    {
        if(!curPtr->isAvailable)
        {
            if(curPtr->coolDown <= currentTime)
            {
                curPtr->isAvailable = true;
                curPtr->coolDown = 0;
                curPtr = curPtr->nextPtr;
            }
            else
                curPtr = curPtr->nextPtr;
        }
        else
            curPtr = curPtr -> nextPtr;

    }

}

// Finds the first available computer in the ComputerLinkedList and returns its pointer
Computer* ComputerLinkedList::findAvailableComputer()
{
    Computer* curPtr = headPtr;
    bool availableComputerFound = false;
    while(!availableComputerFound && curPtr != nullptr)
    {
        if(curPtr->isAvailable == true)
        {
            availableComputerFound = true;
        }
        else
            curPtr = curPtr -> nextPtr;
    }
    return curPtr;
}

// Checks whether there exists at least one available computer in the ComputerLinkedList
bool ComputerLinkedList::isThereAvailableComputer() {

    Computer* curPtr = headPtr;
    bool availableComputerFound = false;
    while(!availableComputerFound && curPtr != nullptr)
    {
        if(curPtr->isAvailable == true)
        {
            availableComputerFound = true;
        }
        else
            curPtr = curPtr -> nextPtr;
    }

    return availableComputerFound;
}









