/**
 * @file: LinkedList.h
 * @assignment_name: 03: Try it out: Fifth Element
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 12/13/2022
 * @brief: This program will cover review Inheritance and give you practice with handling pointers in Linked Lists.
 *
 */

#ifndef INC_03_TRY_IT_OUT_FIFTH_ELEMENT_FIFTHELEMENT_H
#define INC_03_TRY_IT_OUT_FIFTH_ELEMENT_FIFTHELEMENT_H

#include "LinkedList.h"

template<class Type>
class FifthElement: public LinkedList<Type>{

private:


public:

    Type getFifthElement(); //This method returns the data at the fifth node (not index) of the linked list. It will throw a length error (i.e. throw length_error("There is no fifth element");) if there is no fifth element in the list

    void insertNewFifthElement(const Type &value); //This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list.

    void deleteFifthElement(); //This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node.

    void swapFourthAndFifthElement(); //This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.
};

//This method returns the data at the fifth node (not index) of the linked list. It will throw a length error (i.e. throw length_error("There is no fifth element");) if there is no fifth element in the list
template<class Type>
Type FifthElement<Type>::getFifthElement(){
    return LinkedList<Type>::peek(4);
}
//This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list.
template<class Type>
void FifthElement<Type>::insertNewFifthElement(const Type &value){
    int currentNodeNum = 0;
    auto currentNode = this->front;
    //iterate to 4th element.
    while(currentNodeNum < 3){
        currentNodeNum ++;
        currentNode = currentNode->next;
    }

    //add item to list and link surrounding nodes
    Node<Type>*temp = new Node<Type>();
    temp->data = value;
    temp->next = currentNode->next;
    currentNode->next = temp;

    //increase count of list
    this->count++;
}

//This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node.
template<class Type>
void FifthElement<Type>::deleteFifthElement(){
    this->remove(4);
}

//This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.
template<class Type>
void FifthElement<Type>::swapFourthAndFifthElement(){
    int currentNodeNum = 0;
    auto thirdNode = this->front;
    //iterate to 3rd element.
    while(currentNodeNum < 2){
        currentNodeNum ++;
        thirdNode = thirdNode->next;
    }

    auto fourthNode = thirdNode->next;
    auto fifthNode = fourthNode->next;

    //restructure should look like: 1, 2, 3, 5, 4, 6, ...
    //point 4 to 6
    fourthNode->next = fifthNode->next;

    //point 5 to 4
    fifthNode->next = fourthNode;

    //point 3 to 5
    thirdNode->next = fifthNode;
}


#endif //INC_03_TRY_IT_OUT_FIFTH_ELEMENT_FIFTHELEMENT_H
