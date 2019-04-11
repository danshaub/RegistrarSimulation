//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef LIST_H
#define LIST_H

template<class T>
class List{
    public:
        List();
        virtual ~List();

        //Inserts an object at the front of the list
        virtual void insertFront(T d) = 0;
        //Mutatior function for front object
        virtual void setFront(T d) = 0;
        //Accessor function for front object
        virtual T getFront() = 0;
        //Removes the front object
        virtual T removeFront() = 0;

        //Inserts an object at the back of the list
        virtual void insertBack(T d) = 0;
        //Mutatior function for back object
        virtual void setBack(T d) = 0;
        //Accessor function for back object
        virtual T getBack() = 0;
        //Removes the back object
        virtual T removeBack() = 0;

        //Inserts an object at the specified position of the list
        virtual void insertPos(int pos, T d) = 0;
        //Mutator function for object at specified position
        virtual void setPos(int pos, T d) = 0;
        //Accessor function for object at specified position
        virtual T getPos(int pos) = 0;
        //Removes the object at the specified position
        virtual T deletePos(int pos) = 0;

        //Removes the first instance of specified object
        virtual int remove(T d) = 0;
        //Removes the last instance of specified object
        virtual int removeLast(T d) = 0;
        //Finds the first instance of specified object
        virtual int find(T d) = 0;
        //Finds the last instance of specified object
        virtual int findLast(T d) = 0;

        //Returns the next object in the list
        virtual T getNext() = 0;
        //Returns true if there is a next object in the iterator
        virtual bool hasNext() = 0;
        //Resets the list i = 0;erator pointer to the front of the list
        virtual void resetIterator() = 0;

        //Returns true if the list is empty
        virtual bool isEmpty() = 0;
        //Returns the current size of the list
        virtual unsigned int getSize() = 0;
        //Prints the list in array format
        virtual void printList() = 0;

        //Swaps the objects stored at the two positions
        virtual void swapPos(int pos1, int pos2) = 0;
};

template<class T>
List<T>::List(){

}

template<class T>
List<T>::~List(){

}


#endif //LIST_H