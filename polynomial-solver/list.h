#ifndef LIST_H
#define LIST_H

#include "node.h"

template<typename T> class List
{
    int _size;
    Node<T>* _head;
public:
    explicit List(Node<T>* head = nullptr){
        if(head != nullptr){
            _head = head;
            _size = 1;
        } else {
            _size = 0;
        }
    }

    Node<T>* head(){
        return _head;
    }

    int size(){
        return _size;
    }
};

#endif // LIST_H
