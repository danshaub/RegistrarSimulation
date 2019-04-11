//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef WINDOW_H
#define WINDOW_H

#include "GenDoubleLinkedList.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

class Window{
    public:
        //Default constructor
        Window();

        //Default destructor
        ~Window();

        //Sets helping to true
        void startHelping(Student* s);

        //Sets helping to false and begins a new wait time
        void stopHelping();

        //Returns if the window is currently helping
        bool isHelping();

        //adds to current wait time if not helping
        void step();

        //Returns wait times 
        GenDoublyLinkedList<int>* getWaitTimes();

        //string toWindowString();
    
    private:
        //Stores if the window is currently helping
        bool helping;

        //Stores student being helped
        Student *studentBeingHelped;

        //Stores time remaining for current student
        int helpTimeRemaining;

        //Stores wait times
        GenDoublyLinkedList<int> *idleTimes;
};

#endif //WINDOW_H