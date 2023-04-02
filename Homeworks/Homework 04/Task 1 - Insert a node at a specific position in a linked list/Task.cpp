SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    if (position == 0) {
        new_node->next = llist;
        return new_node;
    }

    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    for (int i = 0; i < position; i++) {
        if (current != nullptr) {
            previous = current;
            current = current->next;
        }
    }

    previous->next = new_node;
    new_node->next = current;
    return llist;
}