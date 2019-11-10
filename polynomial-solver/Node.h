#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T _value;
    Node<T>* p_mNext;
    Node<T>* p_mPrev;
public:
    explicit Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr) :
        _value(value), p_mPrev(prev), p_mNext(next){}

    Node<T>* GetNext(){return p_mNext;}
    void SetNext(Node<T>* next){p_mNext = next;}
    Node<T>* GetPrev(){return p_mPrev;}
    void SetPrev(Node<T>* prev){p_mPrev = prev;}
};

#endif // NODE_H
