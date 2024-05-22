#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
void LinkedList<T>::pushFront(const T& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    ++size;
}

template<class T>
void LinkedList<T>::pushBack(const T& data) {
    if (!head) {
        pushFront(data);
        return;
    }
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new Node(data);
    ++size;
}

template<class T>
void LinkedList<T>::pushAfter(const T& data, const T& afterData) {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    Node* curr = head;
    while (curr) {
        if (curr->data == afterData) {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
            ++size;
            return;
        }
        curr = curr->next;
    }
    throw std::invalid_argument("No such element in the list");
}

template<class T>
void LinkedList<T>::pushByInd(const T& data, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        pushFront(data);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < index - 1; ++i) {
        curr = curr->next;
    }
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
    ++size;
}

template<class T>
void LinkedList<T>::delFront() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<class T>
void LinkedList<T>::delBack() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        size = 0;
        return;
    }
    Node* curr = head;
    while (curr->next->next) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    --size;
}

template<class T>
void LinkedList<T>::del(const T& data) {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    if (head->data == data) {
        delFront();
        return;
    }
    Node* curr = head;
    while (curr->next) {
        if (curr->next->data == data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            --size;
            return;
        }
        curr = curr->next;
    }
    throw std::invalid_argument("No such element in the list");
}

template<class T>
void LinkedList<T>::delByInd(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        delFront();
        return;
    }
    Node* curr = head;
    for (int i = 0; i < index - 1; ++i) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    --size;
}

template<class T>
int LinkedList<T>::find(const T& data) {
    Node* curr = head;
    int index = 0;
    while (curr) {
        if (curr->data == data) {
            return index;
        }
        curr = curr->next;
        ++index;
    }
    return -1;
}

template<class T>
T& LinkedList<T>::getByIndex(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

template<class T>
int LinkedList<T>::getSize() const {
    return size;
}

template<class T>
void LinkedList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template<class T>
void LinkedList<T>::print() {
    Node* curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;