#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void pushFront(const T& data);
    void pushBack(const T& data);
    void pushAfter(const T& data, const T& afterData);
    void pushByInd(const T& data, int index);

    void delFront();
    void delBack();
    void del(const T& data);
    void delByInd(int index);

    int find(const T& data);
    T& getByIndex(int index);
    int getSize() const;
    void clear();
    void print();
};

#endif