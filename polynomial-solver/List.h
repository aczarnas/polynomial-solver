//! List class template
/*!
 * \brief Simple double linked list implementation
 * \tparam T Type to work with
 */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

template<typename T> class List
{
    int mSize;
    Node<T>* p_mHead;
    Node<T>* p_mTail;
public:
    //! Default constructor taking optional parameter with head node pointer
    explicit List(Node<T>* head = nullptr){
        if(head != nullptr){
            p_mTail = p_mHead = head;
            mSize = 1;
        } else {
            p_mTail = p_mHead = nullptr;
            mSize = 0;
        }
    }

    //! Destructor
    ~List(){
        clear();
    }

    //! Getter for head pointer
    Node<T>* getHead() {return p_mHead;}
    //! Getter for tail pointer
    Node<T>* getTail() {return p_mTail;}
    //! Getter for list size
    int getSize() {return mSize;}

    //! Adds T type element to list
    /*!
     * \param element value to be added to list
     */
    void append(T element){
        if(mSize == 0){
            p_mHead = p_mTail = new Node<T>(element);
        } else {
            Node<T>* el = new Node<T>(element);
            p_mTail->setNext(el);
            el->setPrev(p_mTail);
            p_mTail = el;
        }
        ++mSize;
    }

    //! Clears list from existing nodes
    void clear(){
        Node<T>* handler = p_mHead;
        while(handler != nullptr){
            Node<T>* next = handler->getNext();
            delete handler;
            --mSize;
            handler = next;
        }
        p_mHead = p_mTail = nullptr;
    }
};

#endif // LIST_H
