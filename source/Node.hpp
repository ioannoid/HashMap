#pragma once

template<class T> class Node 
{
public:
    Node();
    Node(T data);

    void setNext(Node<T>& next);
    void setPrev(Node<T>& prev);

    Node<T>& getNext();
    Node<T>& getPrev();

    T& getData();
private:
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template<class T> Node<T>::Node() { }

template<class T> Node<T>::Node(T data) {
    this->data = data;
}

template<class T> void Node<T>::setNext(Node<T>& next) {
    this->next = &next;
}

template<class T> void Node<T>::setPrev(Node<T>& prev) {
    this->prev = &prev;
}

template<class T> Node<T>& Node<T>::getNext() {
    return *next;
}
template<class T> Node<T>& Node<T>::getPrev() {
    return *prev;
}

template<class T> T& Node<T>::getData() {
    return data;
}