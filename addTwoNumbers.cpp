/* Problem:
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Solution approach: Add node by node and add the vcary over later
Solution time complexity: O(n)

*/
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* A, ListNode* B);

int main() 
{
    cout << stoi("abcd") << endl;
    ListNode a1(9);
    ListNode a2(9);
    ListNode a3(1);
    ListNode b1(1);
    a1.next = &a2;
    a2.next = &a3;
    ListNode *res = addTwoNumbers(&a1, &b1);
    cout << res->val << " " << res->next->val << " " << res->next->next->val << endl;
    return 0;
}

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *result = NULL;
    if (A == NULL && B == NULL) return NULL;
    if (A == NULL) return B;
    if (B == NULL) return A;
    
    ListNode *currA = A->next;
    ListNode *currB = B->next;
    ListNode *digit = new ListNode(A->val + B->val);
    result = digit;
    ListNode* res_curr = result;
    
    while (currA != NULL && currB != NULL) {
        cout << currA->val << " " << currB->val << endl;
        ListNode *tmp = new ListNode(currA->val + currB->val);
        res_curr->next = tmp;
        res_curr = res_curr->next;
        currA = currA->next;
        currB = currB->next;
    }
    if (currA != NULL) res_curr->next = currA;
    if (currB != NULL) res_curr->next = currB;
    cout << res_curr->val << " " << res_curr->next->val << " " << res_curr->next->next->val << endl;

    int carry = 0;
    res_curr = result;
    if (res_curr->val > 9) {
        res_curr->val -= 10;
        carry = 1;
    }
    cout << result->val << " " << result->next->val << " " << result->next->next->val << endl;

    while (res_curr->next != NULL) {
        res_curr = res_curr->next;
        cout << carry << " " << res_curr->val << endl;
        if (carry == 1) {
            res_curr->val += 1;
            carry = 0;
        }
        if (res_curr->val > 9) {
            res_curr->val -= 10;
            carry = 1;
        }
        cout << "x " <<  carry << " " << res_curr->val << endl;
        cout << result->val << " " << result->next->val << " " << result->next->next->val << endl;

    }
    ListNode *temp =  new ListNode(1);
    if (carry == 1) {
        res_curr->next = temp;
    }
    return result;
}
