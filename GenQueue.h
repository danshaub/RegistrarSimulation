//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef GEN_QUEUE_H
#define GEN_QUEUE_H

#include "GenDoubleLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class GenQueue{
    public:
        GenQueue();
        ~GenQueue();

        //inserts at the back of the queue
        void insert(T d);
        //removes from the front of the queue
        T remove();
        //returns the front object without removing it from the queue
        T front();

        //returns the number of elements in the queue
        int getSize();
        //returns true if the queue is empty
        bool isEmpty();
        //prints the queue in array format
        void printQueue();
    
    private:
        //List that contains queue elements
        GenDoublyLinkedList<T> *myQueue;
        int numElements;
};

template<class T>
GenQueue<T>::GenQueue(){
    myQueue = new GenDoublyLinkedList<T>();
    numElements = 0;
}

template<class T>
GenQueue<T>::~GenQueue(){
    delete myQueue;
}

template<class T>
void GenQueue<T>::insert(T d){
    myQueue->insertBack(d);
    numElements++;
}

template<class T>
T GenQueue<T>::remove(){
    //protects against removing from an empty queue
    if(numElements == 0){
        cerr << "Tried to remove from an empty queue\n";
        exit(EXIT_FAILURE);
    }

    numElements--;
    return myQueue->removeFront();
}

template<class T>
T GenQueue<T>::front(){
    //protects against referencing the front of an empty queue
    if(numElements == 0){
        cerr << "Tried to see front of an empty queue\n";
        exit(EXIT_FAILURE);
    }
    
    return myQueue->getFront();
}

template<class T>
int GenQueue<T>::getSize(){
    return numElements;
}

template<class T>
bool GenQueue<T>::isEmpty(){
    return numElements == 0;
}

template<class T>
void GenQueue<T>::printQueue(){
    myQueue->printList();
}

#endif //GEN_QUEUE_H