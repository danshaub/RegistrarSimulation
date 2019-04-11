//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        //Default Constructor
        Student();

        //overloaded constructor, accepts int for how long the student stays at the window
        Student(int timeNeededAtWindow);

        //Destructor
        ~Student();
        
        //Adds to the wait time of the student
        void wait();

        //Lets the student know it is in a line, waiting
        void enterLine();

        //Lets the student know it is no longer waiting
        void enterWindow();

        //Returns how much time the student needs
        int getTimeNeeded();

        //Returns how much time the student has waited
        int getTimeWaited();

        //Returns true if the student is waiting currently
        bool isWaiting();

        //string toStudentString();
    
    private:
        int timeNeeded;
        int timeWaited;

        bool waiting = false;
};

#endif //STUDENT_H