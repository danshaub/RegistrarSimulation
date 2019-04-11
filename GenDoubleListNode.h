//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef GEN_DOUBLE_LIST_NODE_H
#define GEN_DOUBLE_LIST_NODE_H

template<class T>
class GenDoubleListNode{
    public:
        GenDoubleListNode();
        GenDoubleListNode(T d); //Overloaded constructor
        ~GenDoubleListNode();

        T data;
        
        GenDoubleListNode *next;
        GenDoubleListNode *prev;
};

template<class T>
GenDoubleListNode<T>::GenDoubleListNode(){
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

template<class T>
GenDoubleListNode<T>::GenDoubleListNode(T d){
    data = d;
    next = nullptr;
    prev = nullptr;
}

template<class T>
GenDoubleListNode<T>::~GenDoubleListNode(){
    next = nullptr;
    prev = nullptr;
}

#endif //GEN_DOUBLE_LIST_NODE_H