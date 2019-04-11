//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef SIMULATION_H
#define SIMULATION_H

#include "GenDoubleLinkedList.h"
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include "Registrar.h"
#include "Entrance.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Simulation{
    public:
        //Constructor (requires fileName, no default) 
        //Prepares values for simulation
        Simulation(string fileName);

        //Destructor
        ~Simulation();
        
        //Runs Simulation and prints results at the end
        void simulate();
    
    private:
        //Keeps track of what students enter when
        GenDoublyLinkedList<Entrance*> *entrances;
        
        //Keeps track of all students that have entered the simulation
        GenDoublyLinkedList<Student*> *students;

        //Registrar object that is the setting for the simulations
        Registrar *registrar;

        //The number of windows that belong to the Registrar
        int numWindows;

        //Various statistics
        double meanStudentWaitTime;
        double medianStudentWaitTime;
        int maxStudentWaitTime;
        int numStudentsOverTenMinutes;
        double meanWindowIdleTime;
        int maxWindowIdleTime;
        int numWindowsOverFiveMinutes;

        ifstream fileInput;

        //Sets the correct number of windows for the simulation
        void setNumWindows();

        //Sets entrances list with all entry times and the students at those times
        void setEntrances();
        
        //Calculates all statistics and prints them
        void calculateStats();
};



#endif //SIMULATION_H