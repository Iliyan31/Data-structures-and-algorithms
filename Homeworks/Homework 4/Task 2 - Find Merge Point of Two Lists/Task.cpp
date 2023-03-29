int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* A = head1;
    SinglyLinkedListNode* B = head2;

    while(A!=B) {
        if(A->next != nullptr) {
            A = A->next;
        }
        else{
            A = head2;
        }
        
        if(B->next != nullptr) {
            B = B->next;
        }
        else{
            B = head1;
        }
    }
    return A->data;
}