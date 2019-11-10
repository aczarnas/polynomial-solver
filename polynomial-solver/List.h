#ifndef LIST_H
#define LIST_H

#include "Node.h"

template<typename T> class List
{
    int _size;
    Node<T>* _head;
    Node<T>* _tail;
public:
    explicit List(Node<T>* head = nullptr){
        if(head != nullptr){
            _tail = _head = head;
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

    void append(T element){
        if(_size == 0){
            _head = _tail = new Node<T>(element);
        } else {
            Node<T>* el = new Node<T>(element);
            _tail->SetNext(el);
            el->SetPrev(_tail);
            _tail = el;
        }

        ++_size;
    }
};

#endif // LIST_H
