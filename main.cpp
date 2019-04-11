//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Simulation.h"
#include <iostream>

int main(int argc, char **argv){
    //If there is no string passed as an argument
    if(argc < 2){
        cout << "Please enter a file name as an arguement" << endl;
        cout << "Usage: ./assignment4.exe [file path]" << endl;
        return 0;
    }

    //create a new simulation (file validity testing contained in Simulation class)
    Simulation *sim = new Simulation(argv[1]);

    //Run the simulation and prints stats at the end
    sim->simulate();
}
