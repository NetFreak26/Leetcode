/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* ans = NULL;
        ListNode* curr = NULL;
        int c = 0;
        while (l1 != NULL && l2 != NULL) {
            int d = l1->val + l2->val + c;
            l1 = l1->next;
            l2 = l2->next;

            if (ans == NULL) {
                ans = new ListNode(d % 10);
                curr = ans;
            } else {
                curr->next = new ListNode(d % 10);
                curr = curr->next;
            }
            c = d / 10;
        }
        while (l1 != NULL) {
            int d = l1->val + c;
            l1 = l1->next;

            if (ans == NULL) {
                ans = new ListNode(d % 10);
                curr = ans;
            } else {
                curr->next = new ListNode(d % 10);
                curr = curr->next;
            }
            c = d / 10;
        }
        while (l2 != NULL) {
            int d = l2->val + c;
            l2 = l2->next;

            if (ans == NULL) {
                ans = new ListNode(d % 10);
                curr = ans;
            } else {
                curr->next = new ListNode(d % 10);
                curr = curr->next;
            }
            c = d / 10;
        }
        if (c == 1) {
            curr->next = new ListNode(1);
        }
        return ans;
    }
};
