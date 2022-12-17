/**
 * @file: LinkedList.h
 * @assignment_name: 03 Learning Activity: LinkedList
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 12/13/2022
 * @brief: Using pointers to create a LinkedList.
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <iostream>


template<class Type>
struct Node{
    Type data;
    Node<Type> * next;
};

template<class Type>
class LinkedList;

template<class Type>
// Returns an output stream for displaying the LinkedList
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& list);

template<class Type>
class LinkedList{
public:
    LinkedList();// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    ~LinkedList(); //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data); //Adds to the back of the list
    Type peek(int ndx); //Looks at an element at the given ndx value
    void remove(int ndx); //Removes an element at the given ndx position
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
protected:
    Node<Type>* front;
    Node<Type>* back;
    int count;
};

template<class Type>
// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
LinkedList<Type>::LinkedList(){
    front = nullptr;
    back = nullptr;
    count = 0;
}

template<class Type>
//Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
LinkedList<Type>::~LinkedList(){
    Node<Type>* temp = front;

    while(front != nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<class Type>
//Adds to the back of the list
void LinkedList<Type>::insert(Type data){
    Node<Type>*temp = new Node<Type>();
    temp->data = data;

    if(!front){
        this->front = temp;
        this->back = temp;
    }
    else{
        temp->next = nullptr;
        back->next = temp;
        back = temp;
    }
    count++;
}

template<class Type>
//Looks at an element at the given ndx value
Type LinkedList<Type>::peek(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front; //Only use 'auto' when declaring a pointer and assigning a value for it at the same time

    if(ndx >= count){
        throw std::runtime_error("Item does not exist");
    }
    while(currentNodeNum < ndx){
        currentNodeNum ++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}
template<class Type>
//Removes an element at the given ndx position
void LinkedList<Type>:: remove(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front; //Only use 'auto' when declaring a pointer and assigning a value for it at the same time

    if(ndx >= count || ndx < 0){
        throw std::runtime_error("Item does not exist");
    }

    if(ndx == 0){
        front= front->next;
        delete currentNode;
        return;
    }

    while(currentNodeNum < ndx - 1){
        currentNodeNum ++;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    currentNode->next = toDelete->next;
    delete toDelete;
}

template<class Type>
// Returns an output stream for displaying the LinkedList
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& list){
    auto currentNode = list.front;
    while(currentNode){
        out << currentNode->data;
        if(currentNode->next){
            out << " ";
        }//end if
        currentNode = currentNode->next;
    }//end while
    return out;
}

#endif //LINKEDLIST_H
