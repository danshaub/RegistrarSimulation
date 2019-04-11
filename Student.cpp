//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Student.h"
#include <iostream>

using namespace std;

//Default Constructor
Student::Student(){
    timeNeeded = 1;
    timeWaited = 0;
}

//overloaded constructor, accepts int for how long the student stays at the window
Student::Student(int timeNeededAtWindow){
    timeNeeded = timeNeededAtWindow;
    timeWaited = 0;
}

//Destructor
Student::~Student(){}

//Adds to the wait time of the student
void Student::wait(){
    timeWaited++;
}

//Lets the student know it is in a line, waiting
void Student::enterLine(){
    waiting = true;
}

//Lets the student know it is no longer waiting
void Student::enterWindow(){
    waiting = false;
}

//Returns how much time the student needs
int Student::getTimeNeeded(){
    return timeNeeded;
}

//Returns how much time the student has waited
int Student::getTimeWaited(){
    return timeWaited;
}

//Returns true if the student is waiting currently
bool Student::isWaiting(){
    return waiting;
}

/*
string Student::toStudentString(){
    string returnString = "(N: " + to_string(timeNeeded) + ", W: " + to_string(timeWaited);
    if(waiting)
        returnString += ", waiting)";
    else
        returnString += ", not waiting)";
    
    return returnString;
}
*/