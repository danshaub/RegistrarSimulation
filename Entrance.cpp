//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Entrance.h"

//Only constructor requires the number of students and the entrance time
Entrance::Entrance(int numStudents, int entranceTime){
    this->entranceTime = entranceTime;
    newStudents = new GenQueue<Student*>();
    this->numStudents = numStudents;
}

//Destructor
Entrance::~Entrance(){
    delete newStudents;
}

//Returns the next student to enter at the entrance time
Student* Entrance::getNextStudent(){
    return newStudents->remove();
}

//Returns true if there are any more students
bool Entrance::hasNextStudent(){
    return newStudents->getSize() > 0;
}

//Adds a student to the list of students to enter
void Entrance::addStudent(Student *newStudent){
    newStudents->insert(newStudent);
}

//Returns the total number of students that enter at this time
int Entrance::getTotalNumStudents(){
    return newStudents->getSize();
}

//Returns the time at which this entrance happens
int Entrance::getEntranceTime(){
    return entranceTime;
}