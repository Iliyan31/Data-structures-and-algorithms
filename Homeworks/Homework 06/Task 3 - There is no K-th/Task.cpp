#include <iostream>
#include <queue>

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int value;

    Node() = default;
    Node(const int& key, Node* left = nullptr, Node* right = nullptr) : value(key), left(left), right(right) {}
    Node(const Node& n) : value(n.value), left(n.left), right(n.right) {}
    Node& operator=(const Node& n) {
        if (this != &n) {
            delete left;
            delete right;
            this->value = n.value;
            this->left = n.left;
            this->right = n.right;
        }
        return *this;
    }
    ~Node() {
        delete this->left;
        delete this->right;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, const int& value);
    Node* remove(Node* node, const int& value);
    Node* findMax(Node* root) const;
    Node* findMin(Node* root) const;
    void deleteTheSpecificElement(Node* root, const int& k, int& number);
    void levelOrderPrint(Node* root) const;


public:
    BST() : root(nullptr) {}
    BST(const BST& b) : root(b.root) {}
    BST& operator=(const BST& b) {
        if (this != &b) {
            delete root;
            this->root = b.root;
        }
        return *this;
    }
    ~BST() {
        delete root;
    }


    void insert(const int& value);
    void remove(const int& value);
    int findMin() const;
    int findMax() const;
    void levelOrderPrint() const;
    void deleteTheSpecificElement(const int& k);
};


Node* BST::insert(Node* node, const int& value) {
    if (!node) return new Node(value);
    if (node->value < value) {
        node->right = this->insert(node->right, value);
    }
    else {
        node->left = this->insert(node->left, value);
    }
    return node;
}

Node* BST::remove(Node* node, const int& value) {
    if (!node) return nullptr;
    if (node->value < value) {
        node->right = this->remove(node->right, value);
    }
    else if (node->value > value) {
        node->left = this->remove(node->left, value);
    }
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* minInRightSubTree = this->findMin(node->right);  
        node->value = minInRightSubTree->value;
        node->right = this->remove(node->right, node->value);
    }
    return node;
}

Node* BST::findMax(Node* root) const {
    if (root->right) return findMax(root->right);
    return root;
}

Node* BST::findMin(Node* root) const {
    if (root->left) return findMin(root->left);
    return root;
}


void BST::deleteTheSpecificElement(Node* root, const int& k, int& number) {
    if (!root || number > k) return;
    deleteTheSpecificElement(root->right, k, number);
    number++;
    if (k == number) {
        this->remove(root->value);
    }
    deleteTheSpecificElement(root->left, k, number);
}

void BST::levelOrderPrint(Node* root) const {
    if (!root) return;
    std::queue<Node*> que;
    que.push(root);

    while (que.size() != 0) {
        Node* temp = que.front();
        std::cout << temp->value << " ";
        que.pop();

        if (temp->left) {
            que.push(temp->left);
        }

        if (temp->right) {
            que.push(temp->right);
        }
    }
}


void BST::insert(const int& value) {
    if (!root) {
        this->root = new Node(value);
    }
    else {
        this->insert(root, value);
    }
}

void BST::remove(const int& value) {
    this->root = remove(root, value);
}


int BST::findMin() const {
    if (!root) return -1;
    return findMin(root)->value;
}

int BST::findMax() const {
    if (!root) return -1;
    return findMax(root)->value;
}

void BST::levelOrderPrint() const {
    this->levelOrderPrint(this->root);
}

void BST::deleteTheSpecificElement(const int& k) {
    if (!root) return;
    else {
        int num = 0;
        return deleteTheSpecificElement(root, k, num);
    } 
}


int main() {
    int size;
    std::cin >> size;

    int kth;
    std::cin >> kth;

    BST tree;
    
    int number;
    for (int i = 0; i < size; i++) {
        std::cin >> number;
        tree.insert(number);
    }

    tree.deleteTheSpecificElement(kth);

    tree.levelOrderPrint();

    return 0;
}