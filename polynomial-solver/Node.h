#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T _value;
    Node<T>* _next;
public:
    explicit Node(T value, Node<T>* next) :
        _value(value), _next(next){}

    Node<T>* Next(){
        return _next;
    }
};

#endif // NODE_H
