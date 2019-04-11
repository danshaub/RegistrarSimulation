//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#include "Simulation.h"

using namespace std;

//Constructor (requires fileName, no default) 
//Prepares values for simulation
Simulation::Simulation(string fileName){
    //opens file and checks its validity
    fileInput.open(fileName);
    if(!fileInput.is_open()){
        cerr << "Invalid file: file path does not exist\n";
        exit(EXIT_FAILURE);    
    }

    //initializes the two lists
    entrances = new GenDoublyLinkedList<Entrance*>();
    students = new GenDoublyLinkedList<Student*>();

    //gathers values from the input file
    setNumWindows();
    setEntrances();
    
    //creates the Registrar setting
    registrar = new Registrar(numWindows);

}

//Destructor
Simulation::~Simulation(){
    fileInput.close();
    delete entrances;
    delete students;
    delete registrar;
}

//Sets the correct number of windows for the simulation
void Simulation::setNumWindows(){
    //gets input from the first line of the input file
    string line = "";
    getline(fileInput, line);

    //tries to convert that line to an int
    try{
        numWindows = stoi(line);
        if(numWindows < 0)
            throw 0; 
    }
    //if it fails, the user is notified and the program is stopped
    catch(invalid_argument e){
        cerr << "Invalid file: file contents invalid at line 1\n";
        exit(EXIT_FAILURE);
    }
    catch(int i){
        cerr << "Invalid file: file contans negative number at line 1\n";
        exit(EXIT_FAILURE);
    }
}

//Sets entrances list with all entry times and the students at those times
void Simulation::setEntrances(){
    //traverses through each remaining line of the file
    string line = "";
    int lineNumber = 1;
    int previousTime = -1;
    //try to create Entrance objects from the file
    try{ 
        //each new entrance time
        while(getline(fileInput, line)){
            //When is the entrance?
            lineNumber++;
            int entranceTime = stoi(line);

            //protect against negative numbers
            if(entranceTime < 0)
                throw 1;

            //protect against non increasing times for entrances
            if(entranceTime <= previousTime)
                throw 2;

            //allows check for non increasing times
            previousTime = entranceTime;


            //How many students for this entrance?

            //each new number of students
            if(!getline(fileInput, line))
                //thrown if number of lines is invalid
                throw 0;
            
            lineNumber++;
            int numNewStudents = stoi(line);

            //protects against 0 or negative students
            if(numNewStudents < 1)
                throw 3;

            //Makes the new Entrance (accessed here temporarily beofre adding it to the list)
            Entrance *temp = new Entrance(numNewStudents, entranceTime);

            //Makes new students and adds them to the temp Entrance opject
            for(int i = 0; i < numNewStudents; i++){
                //each student at this arrival time
                if(!getline(fileInput, line))
                    //thrown if number of lines is invalid
                    throw 0;

                lineNumber++;
                int waitTime = stoi(line);

                //protect against negative numbers
                if(waitTime < 0)
                    throw 1;

                //adds a new student to the entrance
                temp->addStudent(new Student(waitTime)); 
            }  
            //adds the temp Entrance to the list of entrances
            entrances->insertBack(temp);
        }
    }
    //Catch stoi() errors
    catch(invalid_argument e){
        cerr << "Invalid file: file contents invalid at line " << lineNumber << endl;
        exit(EXIT_FAILURE);
    }
    //Catch invalid integers in different contexts
    catch(int i){
        if(i==0)
            cerr << "Invalid file: file contains illegal number of lines" << endl; 
        else if(i == 1)
            cerr << "Invalid file: file contans negative number at line " << lineNumber << endl;
        else if(i == 2)
            cerr << "Invalid file: entrance times not in strict ascending order at line " << lineNumber << endl;
        else if(i == 3)
            cerr << "Invalid file: tried creating an entrance with zero students at line " << lineNumber << endl;
        exit(EXIT_FAILURE);
    }
}

//Runs Simulation and prints results at the end
void Simulation::simulate(){
    int timeStep = 0;
    //Run while there are more entrances, more students waiting in line, and students are being helped
    while(!entrances->isEmpty() || registrar->studentsInLine() || registrar->studentsAtWindows()){
        //If there are any more entrances, get the next one at the correct time...
        if(!entrances->isEmpty() && (entrances->getFront()->getEntranceTime() == timeStep)){
            //... and remove it from the list...
            Entrance *temp = entrances->removeFront();

            //...then add the students to the list of students and the registrar
            while(temp->hasNextStudent()){
                Student *newStudent = temp->getNextStudent();

                students->insertBack(newStudent);
                registrar->AddStudent(newStudent);
            }
        }
        
        registrar->step();

        //Iterate through list of students and make them wait if they are in line
        students->resetIterator();
        while(students->hasNext()){
            Student *temp = students->getNext();
            if(temp->isWaiting()){
                temp->wait();
            }
        }

        timeStep++;
    }

    calculateStats();
}

//Calculates all statistics and prints them
void Simulation::calculateStats(){
    //temporary list of the wait times for all students
    GenDoublyLinkedList<int> *studentWaitTimes = new GenDoublyLinkedList<int>();

    double totalWait = 0;

    //ensures students list is ready to be traversed
    students->resetIterator();
    
    //Traverses all students and gathers wait times (and calculates stuff along the way)
    while(students->hasNext()){
        Student *temp = students->getNext();

        //add the wait time to the total
        totalWait += temp->getTimeWaited();

        //if it was over 10 steps, add to the count of over 10
        if(temp->getTimeWaited() > 10){
            numStudentsOverTenMinutes++;
        }

        //if it was the longest wait time up to that point, update longest variable
        if(temp->getTimeWaited() > maxStudentWaitTime){
            maxStudentWaitTime = temp->getTimeWaited();
        }

        //add the wait time to the list
        studentWaitTimes->insertBack(temp->getTimeWaited());
    }  

    //calculates the mean wait time
    meanStudentWaitTime = totalWait/studentWaitTimes->getSize();

    //finds median wait time
    studentWaitTimes->sort();
    medianStudentWaitTime = studentWaitTimes->getPos(studentWaitTimes->getSize()/2);

    //WINDOW TIMES

    Window **windows = registrar->getWindows();
    int numWindows = registrar->getNumWindows();

    //used for calculating mean idle times
    double totalNumIdles = 0;
    double totalIdleTime = 0;

    maxWindowIdleTime = -1;

    //Check each window!
    for(int i = 0; i < numWindows; i++){
        bool overFiveMins = false;

        GenDoublyLinkedList<int> *idleTimes = windows[i]->getWaitTimes();
        idleTimes->resetIterator();

        //check each idle time for the current window
        while(idleTimes->hasNext()){
            int temp = idleTimes->getNext();

            //Times of zero are not counted (cause that ain't an idle)!
            if(temp != 0){
                totalNumIdles++;
                totalIdleTime += temp;
                
                //if the current window ever idles for longer than 10 minutes then set this to true
                if(temp > 10){
                    overFiveMins = true;
                }

                //if the current idle time is greater than the max idle time then update the max
                if(temp > maxWindowIdleTime){
                    maxWindowIdleTime = temp;
                }
            }
        }

        if(overFiveMins){
            numWindowsOverFiveMinutes++;
        }
    }

    //calculate the mean idle time
    if(totalNumIdles != 0)
        meanWindowIdleTime = totalIdleTime/totalNumIdles;
    else{
        meanWindowIdleTime = 0;
        maxWindowIdleTime = 0;        
    }
    
    //print everything
    cout << "Mean student wait time --------------------  " << meanStudentWaitTime << endl;
    cout << "Median student wait time ------------------  " << medianStudentWaitTime << endl;
    cout << "Longest student wait time -----------------  " << maxStudentWaitTime << endl;
    cout << "Sutdents waiting over 10 minutes ----------  " << numStudentsOverTenMinutes << endl;
    cout << "Mean window idle time ---------------------  " << meanWindowIdleTime << endl;
    cout << "Longest window idle time ------------------  " << maxWindowIdleTime << endl;
    cout << "Number of windows idle mre than 5 minutes -  " << numWindowsOverFiveMinutes << endl;
}
