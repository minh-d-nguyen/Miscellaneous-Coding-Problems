ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* start = NULL;
    if (A == NULL) return A;
    if (A->next == NULL) return A;
    if (A->next->val == A->val) {
        while (A != NULL && A->next != NULL && A->next->val == A->val) {
            while (A->next != NULL && A->next->val == A->val) {
                ListNode* temp = A;
                A = A->next;
                delete(temp);
            }
            start = A->next;
            delete(A);
            A = start;
        }
    }
    if (A == NULL || A->next == NULL) return A;
    ListNode *curr = A->next;
    ListNode *prev = A;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == curr->val) {
            while (curr->next != NULL && curr->next->val == curr->val) {
                ListNode* temp = curr;
                curr = curr->next;
                delete(temp);
            }
            ListNode* temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete(temp);
        }
        if (curr != NULL && curr->next != NULL && curr->next->val != curr->val) {
            prev = curr;
            curr = curr->next;
        }
    }
    return A;
}
