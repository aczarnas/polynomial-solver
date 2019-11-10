#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T _value;
    Node<T>* _next;
    Node<T>* _prev;
public:
    explicit Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr) :
        _value(value), _prev(prev), _next(next){}

    Node<T>* GetNext(){return _next;}
    void SetNext(Node<T>* next){_next = next;}
    Node<T>* GetPrev(){return _prev;}
    void SetPrev(Node<T>* prev){_prev = prev;}
};

#endif // NODE_H
