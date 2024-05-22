#include <iostream>

template <typename T>
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
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void pushFront(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    void pushBack(const T& data) {
        if (!head) {
            pushFront(data);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
        ++size;
    }

    void pushAfter(const T& data, const T& afterData) {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        Node* current = head;
        while (current) {
            if (current->data == afterData) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                current->next = newNode;
                ++size;
                return;
            }
            current = current->next;
        }
        throw std::invalid_argument("No such element in the list");
    }

    void pushByInd(const T& data, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            pushFront(data);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
        ++size;
    }

    void delFront() {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
    }

    void delBack() {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            size = 0;
            return;
        }
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        --size;
    }

    void del(const T& data) {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        if (head->data == data) {
            delFront();
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                --size;
                return;
            }
            current = current->next;
        }
        throw std::invalid_argument("No such element in the list");
    }

    void delByInd(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            delFront();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        --size;
    }

    int find(const T& data) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == data) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    T& getByIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list;

    try {
        list.pushFront(5);
        list.pushFront(10);
        list.pushBack(15);
        list.pushAfter(20, 5);

        std::cout << "List after insertion: ";
        list.print();

        list.pushByInd(25, 2);

        std::cout << "List after inserting at index 2: ";
        list.print();

        int index = list.find(25);
        if (index != -1) {
            std::cout << "Element 25 found at index " << index << std::endl;
        } else {
            std::cout << "There is no such element" << std::endl;
        }

        list.del(20);

        std::cout << "List after removing 20: ";
        list.print();

        list.delFront();
        list.delBack();

        std::cout << "List after removing first and last elements: ";
        list.print();

        int element = list.getByIndex(1);
        std::cout << "Element at index 1: " << element << std::endl;

        list.pushByInd(30, 10); // Попытка вставки за пределами списка
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
