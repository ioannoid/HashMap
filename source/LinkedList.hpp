#pragma once

#include <initializer_list>

#include "Node.hpp"

template<class T> class LinkedList 
{
public:
    LinkedList();
    LinkedList(const std::initializer_list<T>& data);

    const int& length();
    T& insert(int pos, T data);
    T& append(T data);
    T& at(int pos);
    Node<T>& nodeAt(int pos);

    T& begin();
    T& end();

private:
    Node<T>* first;
    Node<T>* last;

    int size;
};

template<class T> LinkedList<T>::LinkedList() : size(0) { }

template<class T> LinkedList<T>::LinkedList(const std::initializer_list<T>& data) : size(data.size()) {
    first = new Node<T>((int*) data.begin());

    Node<T>* prevNode = first;
    for(T i : data) {
        Node<T>* nextNode = new Node<T>(i);
        nextNode->setPrev(*prevNode);
        prevNode->setNext(*nextNode);
        prevNode = nextNode;
    }
}

template<class T> const int& LinkedList<T>::length() {
    return size;
}

template<class T> T& LinkedList<T>::insert(int pos, T data) {
    if(pos == size || pos == -1) {
        return this->append(data);
    }

    Node<T>* location = &this->nodeAt(pos);
    Node<T>* newPrev = &location->getPrev();
    Node<T>* newNode = new Node<T>(data);

    newNode->setPrev(*newPrev);
    newNode->setNext(*location);
    if(pos != 0) newPrev->setNext(*newNode);
    else first = newNode;

    size++;
    return newNode->getData();
}

template<class T> T& LinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);

    newNode->setPrev(*last);

    if(size != 0) last->setNext(*newNode);
    else first = newNode;

    last = newNode;
    size++;

    return last->getData();
}

template<class T> T& LinkedList<T>::at(int pos) {
    if(pos == -1 || pos == size - 1) return last->getData();
    if(pos >= size) {
        exit(0);
    }

    Node<T>* nextNode = first;
    for(int i = 1; i < pos; i++) nextNode = &nextNode->getNext();

    return nextNode->getData();
}

template<class T> Node<T>& LinkedList<T>::nodeAt(int pos) {
    if(pos == -1 || pos == size - 1) return *last;
    if(pos >= size) {
        exit(0);
    }

    Node<T>* nextNode = first;
    for(int i = 1; i < pos; i++) nextNode = &nextNode->getNext();

    return *nextNode;
}

template<class T> T& LinkedList<T>::begin() {
    return first->getData();
}

template<class T> T& LinkedList<T>::end() {
    return last->getData();
}