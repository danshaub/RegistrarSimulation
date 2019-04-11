//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Window.h"
#include "GenQueue.h"
#include <iostream>
#include <string>

class Registrar{
    public:
        //Default Constructor, 1 window
        Registrar();

        //Overloaded constructor, takes number of windows as a parameter
        Registrar(int numberWindows);

        //Destructor
        ~Registrar();

        //Perform actions for the current time step
        void step();

        //Adds a student to the line of students
        void AddStudent(Student *newStudent);

        //Returns a string representation of the Registrar's office (not needed)
        //string toRegistrarString();

        //Returns true if there are students in line
        bool studentsInLine();

        //Returns true if there are students being helped
        bool studentsAtWindows();

        //Returns the array of windows
        Window** getWindows();

        //Returns how many windows exist
        int getNumWindows();

    private:
        //Its a queue that acts as a line!
        GenQueue<Student*> *line;

        // array of window pointers
        Window **windows; 

        // Stores how many windows exist
        int numWindows;
};


#endif //REGISTRAR_H