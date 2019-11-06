#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T _value;
    Node<T>* _next;
public:
    explicit Node(T value, Node<T>* next = nullptr) :
        _value(value), _next(next){}

    Node<T>* GetNext(){
        return _next;
    }

    void SetNext(Node<T>* next){
        _next = next;
    }
};

#endif // NODE_H
