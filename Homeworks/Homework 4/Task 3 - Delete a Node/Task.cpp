SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(position == 0) {
        if(llist !=nullptr) {
            SinglyLinkedListNode* tempHead = llist;
            llist = llist->next;
            delete tempHead;
        }
        return llist;
    }
    if (llist == nullptr) {
      throw std::out_of_range("Invalid remove index, list is empty");
    }
    
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    for(int i=0; i<position; i++) {
        if(current->next!=nullptr) {
            previous = current;
            current = current->next;
        }
        else {
           throw std::out_of_range("Cannot insert in invalid position");
        }
    }
    previous->next = current->next;
    delete current;
    return llist;
}