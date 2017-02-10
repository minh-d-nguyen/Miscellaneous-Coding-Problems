/* Problem:
Given a singly linked list, modify the value of first half nodes such that :

1st node’s new value = the last node’s value - first node’s current value
2nd node’s new value = the second last node’s value - 2nd node’s current value,
and so on …

Solution approach: Use recursion, when the function returns utilize the fact
that it goes backward in the list to simultaneously update the first half 
nodes.

Time complexity: O(n)
Space complexity: *constant*
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
    int *curr = new int;
    *curr = 0;
    ListNode *curr_node = A;
    int len = 0;
    while (curr_node != NULL) {
        len++; 
        curr_node = curr_node->next;
    }
    curr_node = A;
    subtractList(A, &curr_node, curr, len);
    return A;
}

 void subtractList(ListNode *curr, ListNode **to_update, int *curr_ind, int len)
 {
     if (curr == NULL) return;
     subtractList(curr->next, to_update, curr_ind, len);
     if (*curr_ind < len/2) {
         ListNode *update = *to_update;
         update->val = curr->val - update->val;
         (*to_update) = (*to_update)->next;
         (*curr_ind)++;
     }
     return;
 }
