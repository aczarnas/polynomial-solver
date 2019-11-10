//! Node class template
/*!
 * \brief Simple node implementation to use with list
 * \tparam T Type to work with
 */

#ifndef NODE_H
#define NODE_H

template<typename T> class Node
{
    T mValue;
    Node<T>* p_mPrev;
    Node<T>* p_mNext;
public:
    //! Default constructor for Node
    /*!
     * \param value T type value of new Node
     * \param prev optional pointer to previous Node
     * \param next optional pointer to next Node
     */
    explicit Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr) :
        mValue(value), p_mPrev(prev), p_mNext(next){}

    //! Getter for Node's value
    T getValue() {return mValue;}
    //! Getter for next Node on List
    Node<T>* getNext(){return p_mNext;}
    //! Setter for next Node on List
    void setNext(Node<T>* next){p_mNext = next;}
    //! Getter for previous Node on List
    Node<T>* getPrev(){return p_mPrev;}
    //! Setter for previous Node on List
    void setPrev(Node<T>* prev){p_mPrev = prev;}
};

#endif // NODE_H
