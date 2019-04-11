//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Registrar.h"

//Default Constructor, 1 window
Registrar::Registrar(){
    numWindows = 1;

    //creates an array of windows with one window
    windows = new Window*[1];
    windows[0] = new Window();

    //initializes the line
    line = new GenQueue<Student*>();
}

//Overloaded constructor, takes number of windows as a parameter
Registrar::Registrar(int numberWindows){
    numWindows = numberWindows;

    //creates an array of windows with numberWindows windows
    windows = new Window*[numberWindows];

    //Initializes each of the indicies of the array
    for(int i = 0; i < numWindows; i++){
        Window *temp = new Window();
        windows[i] = temp;
    }

    //initializes the line
    line = new GenQueue<Student*>();
}

//Destructor
Registrar::~Registrar(){
    delete[] windows;
    delete line;
}

//Adds a student to the line of students
void Registrar::AddStudent(Student *newStudent){
    //you gotta let the student know it's entering the line!
    newStudent->enterLine();

    //then add it to the line!
    line->insert(newStudent);
}

//Perform actions for the current time step
void Registrar::step(){
    for(int i = 0; i < numWindows; i++){
        //step for each window
        windows[i]->step();

        //after, check for open windows and waiting students and assign students to the windows!
        if(!windows[i]->isHelping() && !line->isEmpty()){
            windows[i]->startHelping(line->remove());
        }
    }
}

/*
//Returns a string representation of the Registrar's office
string Registrar::toRegistrarString(){
    string returnString = "Registrar:\n{\n";
    for(int i = 0; i < numWindows; i++){
        returnString += "Window: " + to_string(i+1) + "\n" + windows[i]->toWindowString() + "\n";
    }

    returnString += "There are " + to_string(line->getSize()) + " students in line\n}";

    return returnString;
}
*/

//Returns true if there are students in line
bool Registrar::studentsInLine(){
    return !line->isEmpty();
}

//Returns true if there are students being helped
bool Registrar::studentsAtWindows(){
    //iterate through array of windows
    for(int i = 0; i < numWindows; i++){
        if(windows[i]->isHelping())
            //if any are 
            return true;
    }
    return false;
}

//Returns the array of windows
Window** Registrar::getWindows(){
    return windows;
}

//Returns how many windows exist
int Registrar::getNumWindows(){
    return numWindows;
}
