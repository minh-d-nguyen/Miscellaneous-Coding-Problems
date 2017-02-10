/* Problem:
   Given a list, rotate the list to the right by k places, where k is non-negative.

   Solution approach: Only modify the pointers at the new head and the new tail 
   */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int curr_index = 0;
    ListNode* curr_node = A;
    int length = 0;
    if (A == NULL) return NULL;
    if (A->next == NULL) return A;
    while (curr_node->next != NULL) {
        length++;
        curr_node = curr_node->next;
    }
    length++;
    B = B%length;
    curr_node->next = A;
    curr_node = A;
    while (curr_index < length - B - 1) {
        curr_node = curr_node->next;
        curr_index++;
    }
    ListNode* tail = curr_node;
    ListNode* head = tail->next;
    tail->next = NULL;
    return head;
}
