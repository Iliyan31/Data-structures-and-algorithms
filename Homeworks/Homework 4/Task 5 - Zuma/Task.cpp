#include <iostream>
#include <utility>
#include <vector>

int numberData = 0;

struct Node {
    std::pair<int, int> data;
    Node* next = nullptr;
    Node* previous = nullptr;

    Node() = default;
    Node(const int& data, const int& position, Node* next = nullptr, Node* previous = nullptr) : next(next), previous(previous) {
        this->data.first = data;
        this->data.second = position;
    }
};

class DoublyLinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;
public:
    int size = 0;
    int count = 0;
    std::vector<Node*> vec;

    DoublyLinkedList() = default;
    ~DoublyLinkedList();

    void push_back(const int& data, const int& position);
    void removeElements(Node* temp1, Node* temp2);
    void func(Node* node);
    void push_at(const int& data, int& position);
    void pop_back(Node* node);
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

void DoublyLinkedList::push_back(const int& data, const int& position) {
    Node* newNode = new Node(data, position);

    if (head == nullptr) head = newNode;
    if (tail != nullptr) tail->next = newNode;

    newNode->next = nullptr;
    newNode->previous = tail;
    tail = newNode;
    size++;
    vec.push_back(newNode);
}

void DoublyLinkedList::removeElements(Node* temp1, Node* temp2) {

    Node* Previous = temp1->previous;
    Node* Next = temp2->next;

    if (Previous) {
        Previous->next = nullptr;
        temp1->previous = nullptr;
    }
    if (Next) {
        Next->previous = nullptr;
        temp2->next = nullptr;
    }

    pop_back(temp2);

    if (Previous && Next) {
        Previous->next = Next;
        Next->previous = Previous;

        if (Previous->data.first == Next->data.first) {
            func(Previous);
        }
    }

    else if (Previous && !Next) tail = Previous;
    else if (!Previous && Next) head = Next;
    else {
        head = nullptr;
        tail = nullptr;
    }

}

void DoublyLinkedList::func(Node* node) {
    Node* temp1 = node;
    Node* temp2 = node;
    int counter = 1;

    if (temp1->previous) {
        while (temp1->previous && temp1->previous->data.first == node->data.first) {
            temp1 = temp1->previous;
            counter++;
        }
    }

    if (temp2->next) {
        while (temp2->next && temp2->next->data.first == node->data.first) {
            temp2 = temp2->next;
            counter++;
        }
    }

    if (counter > 2) {
        removeElements(temp1, temp2);
    }
}

void DoublyLinkedList::push_at(const int& data, int& position) {
    Node* newNode = new Node(data, numberData);


    Node* temp = head;
    temp = vec[position];

    vec.push_back(newNode);

    if (temp != nullptr) {
        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->previous = newNode;
        }
    }

    this->size++;
    this->count = this->size;

    func(newNode);
    this->count -= this->size;
    numberData++;
}

void DoublyLinkedList::pop_back(Node* node) { 
    while (node) {
        Node* nodeToDelete = node;

        if (node->previous) {
            node = node->previous;
            node->next = nullptr;
        }
        else {
            delete node;
            size--;
            return;
        }

        delete nodeToDelete;
        size--;
    }
}

void DoublyLinkedList::print() const {
    Node* _head = this->head;
    while (_head) {
        std::cout << _head->data.first << " ";
        _head = _head->next;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    int number;
    DoublyLinkedList d;

    for (int i = 0; i < size; i++) {
        std::cin >> number;
        d.push_back(number, numberData++);
    }

    int size2;
    std::cin >> size2;
    std::pair<int, int> p;
    std::vector<int> vec;

    for (int i = 0; i < size2; i++) {

        if (d.size == 0) {
            vec.push_back(-2);
            continue;
        }

        std::cin >> p.first >> p.second;
        d.push_at(p.second, p.first);
        vec.push_back(d.count);
    }

    if (d.size == 0) {
        vec.push_back(-1);
    }

    bool flag = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == -2) {
            std::cout << "Game Over\n";
            flag = true;
            continue;
        }
        if (vec[i] > -1) {
            std::cout << vec[i] << "\n";
        }       
    }
    if (vec[vec.size()-1] == -1) {
        std::cout << -1;
    }
    else {
        d.print();
    }
    
    return 0;
}