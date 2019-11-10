#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T mValue;
    Node<T>* p_mPrev;
    Node<T>* p_mNext;
public:
    explicit Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr) :
        mValue(value), p_mPrev(prev), p_mNext(next){}

    T getValue() {return mValue;}
    Node<T>* getNext(){return p_mNext;}
    void setNext(Node<T>* next){p_mNext = next;}
    Node<T>* getPrev(){return p_mPrev;}
    void setPrev(Node<T>* prev){p_mPrev = prev;}
};

#endif // NODE_H
