/* Problem:
Given a singly linked list, modify the value of first half nodes such that :

1st node’s new value = the last node’s value - first node’s current value
2nd node’s new value = the second last node’s value - 2nd node’s current value,
and so on …

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* subtract(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A == NULL || A->next == NULL) return A;
    unsigned len = 0;
    ListNode *curr = A;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    unsigned half_len = len/2;
    unsigned count = 0;
    vector<int> last_half;
    curr = A;
    while (curr != NULL && count < len) {
        if (count >= len/2) {
            last_half.push_back(curr->val);
        }
        curr = curr->next;
        count++;
    }
    count = 0;
    curr = A;
    while (count < half_len) {
        curr->val = last_half[last_half.size() - count - 1] - curr->val;
        count++;
        curr = curr->next;
    }
    return A;
}
