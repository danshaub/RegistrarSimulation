//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "GenQueue.h"
#include "Student.h"

class Entrance{
    public:
        //Only constructor requires the number of students and the entrance time
        Entrance(int numStudents, int entranceTime);

        //Destructor
        ~Entrance();

        //Returns the next student to enter at the entrance time
        Student* getNextStudent();

        //Returns true if there are any more students
        bool hasNextStudent();

        //Adds a student to the list of students to enter
        void addStudent(Student *newStudent);

        //Returns the total number of students that enter at this time
        int getTotalNumStudents();

        //Returns the time at which this entrance happens
        int getEntranceTime();

    private:
        //Stores all the students for the entrance
        GenQueue<Student*> *newStudents;

        //Stores how many students there are
        int numStudents;

        //Stores what time the entrance happens
        int entranceTime;
};

#endif //ENTRANCE_H