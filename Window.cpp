//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Window.h"
using namespace std;

//Default constructor
Window::Window(){
    idleTimes = new GenDoublyLinkedList<int>();
    idleTimes->insertBack(-1);
    studentBeingHelped = nullptr;
}

//Default destructor
Window::~Window(){
    studentBeingHelped = nullptr;
    delete idleTimes;
}

//Sets helping to true and stores a student
void Window::startHelping(Student *s){
    studentBeingHelped = s;
    helpTimeRemaining = studentBeingHelped->getTimeNeeded();
    studentBeingHelped->enterWindow();
    helping = true;
}

//Sets helping to false, and begins a new wait time, and dismisses the student
void Window::stopHelping(){
    studentBeingHelped = nullptr;
    helping = false;
    idleTimes->insertBack(0);
}

//Returns if the window is currently helping
bool Window::isHelping(){
    return helping;
}

//adds to current wait time if not helping. If help session finished, the student is dismissed
void Window::step(){
    if(helping){
        helpTimeRemaining--;
        //if the session is finished, the student is immeadiately dismissed
        if(helpTimeRemaining == 0){
            stopHelping();
        }
    }
    else{
        idleTimes->setBack(idleTimes->getBack()+1);
    }
}

//Returns wait times 
GenDoublyLinkedList<int>* Window::getWaitTimes(){
    return idleTimes;
}

/*
string Window::toWindowString(){
    string returnString = "[";
    if(helping){
        returnString += "Helping: " + studentBeingHelped->toStudentString() + " for " + to_string(helpTimeRemaining) + " more steps.]\n";
    }
    else{
        returnString += "Not Helping.]\n";
    }

    returnString += "[";
    idleTimes->resetIterator();
    while(idleTimes->hasNext()){
        returnString += to_string(idleTimes->getNext()) + ","; 
    }

    returnString += "\b]";

    return returnString;
}
*/