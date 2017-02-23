/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
int hash_val(int value);

int hash_val(int value) {
    return value % 17;
}

bool has_cycle(Node* head) {
    if (head == NULL) return false;
    Node* addresses[17];
    for (int i = 0; i < 17; i++) {
        addresses[i] = NULL;
    }
    Node* curr = head;
    while (curr != NULL) {
        int value = (size_t) curr;
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        int key = hash_val(value);
        if (addresses[key] == NULL) {
            addresses[key] = temp;
        } else {
            Node *cur_pos = addresses[key];
            while (cur_pos != NULL) {
                if (cur_pos->data = value) return true; 
                cur_pos = cur_pos->next;
            }
            temp->next = addresses[key];
            addresses[key] = temp;
        }
        curr = curr->next;
    }
    return false;
}
