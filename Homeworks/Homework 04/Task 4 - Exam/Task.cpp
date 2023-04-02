#include <vector>
#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next = nullptr;
    Node* previous = nullptr;

    Node() = default;
    Node(const int& data, Node* next = nullptr, Node* previous = nullptr) : data(data), next(next), previous(previous) {}
};

class DoublyLinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;
public:
    int size = 0;
    DoublyLinkedList() = default;
    ~DoublyLinkedList();

    void push_back(const int& data);
    void pop_back();
    void milen();
    void print() const;
};

DoublyLinkedList::~DoublyLinkedList() {
    Node* new_head = this->head;
    while (new_head) {
        Node* _next = new_head->next;
        delete new_head;
        new_head = _next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}

void DoublyLinkedList::push_back(const int& data) {
    Node* newNode = new Node(data);

    if (head == nullptr) head = newNode;
    if (tail != nullptr) tail->next = newNode;

    newNode->next = nullptr;
    newNode->previous = tail;
    tail = newNode;
    size++;

    if (size == 1) {
        mid = newNode;
    }
    else if (size % 2 == 0) {
        mid = mid->next;
    }
}

void DoublyLinkedList::pop_back() {
    if (tail) {
        Node* nodeToDelete = tail;
        tail = tail->previous;

        if (size % 2 == 0) {
            if (mid->previous != nullptr) {
                mid = mid->previous;
            }
        }
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete nodeToDelete;
        
        size--;
    }
}



void DoublyLinkedList::milen() {
    if (size > 1) {
        Node* temp = mid->previous;
        Node* tempHead = head;
        temp->next = nullptr;
        mid->previous = nullptr;
        tail->next = head;
        head->previous = tail;
        head = mid;
        
        if (size % 2 == 0) {
            mid = tempHead;
        }
        else {
            mid = tail;
        }
        tail = temp;
    }
}

void DoublyLinkedList::print() const {
    Node* _head = this->head;
    while (_head) {
        std::cout << _head->data << " ";
        _head = _head->next;
    }
}



void addNumber(const std::string& str, DoublyLinkedList& list) {
    int number = 0;
    for (int i = 4; str[i] != '\0'; i++) {
        number = (number * 10 + (str[i] - '0'));
    }
    list.push_back(number);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    std::string str;
    DoublyLinkedList list;

    std::cin.ignore();
    for (int i = 0; i < size; i++) {
        std::getline(std::cin, str);
        if (str[0] == 'a') {
            addNumber(str, list);
            continue;
        }
        if (str[0] == 'g') {
            list.pop_back();
            continue;
        }
        if (str[0] == 'm') {
            list.milen();
        }
    }

    std::cout <<list.size << "\n";
    list.print();

    return 0;
}
