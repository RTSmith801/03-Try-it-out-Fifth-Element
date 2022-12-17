/**
 * @file: LinkedList.h
 * @assignment_name: 03: Try it out: Fifth Element
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 12/13/2022
 * @brief: This program will cover Inheritance and practice handling pointers in Linked Lists.
 *
 */

#ifndef FIFTH_ELEMENT_H
#define FIFTH_ELEMENT_H
#include "LinkedList.h"


class FifthElement: public LinkedList<class Type>{

    private:

    public:

        template<class Type>
        Type getFifthElement(); //This method returns the data at the fifth node (not index) of the linked list. It will throw a length error (i.e. throw length_error("There is no fifth element");) if there is no fifth element in the list

        template<class Type>
        void insertNewFifthElement(const Type &value); //This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list.

        void deleteFifthElement(); //This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node.

        void swapFourthAndFifthElement(); //This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.
};




#endif //FIFTH_ELEMENT__H
