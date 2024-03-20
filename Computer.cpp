/*
* Author : Muhammed Ümit TAVUS
* ID: 22203317
* Section : 2
* Homework : 2
* Description : Source file for the Computer class
*/

#include "Computer.h"

// Initializing static data member
int Computer::currentID = 0;

// Default constructor for the computer class
Computer ::Computer()
{
    id = currentID;
    isAvailable = true;
    coolDown = 0;
    nextPtr = nullptr;
    currentID++;
}

// Destructor for the computer class
Computer ::~Computer() {}

// = operator overload
Computer &Computer::operator=(const Computer &right) {
    if(&right != this)
    {
        id = right.id;
        isAvailable = right.isAvailable;
        coolDown = right.coolDown;
        nextPtr = nullptr;
    }
    return *this;
}

