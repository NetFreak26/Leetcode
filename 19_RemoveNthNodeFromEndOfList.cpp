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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            curr = curr->next;
            l++;
        }
        if (n == l) {
            return head->next;
        }
        curr = head;
        while (n < l-1) {
            curr = curr->next;
            l--;
        }
        curr->next = curr->next->next;
        return head;
    }
};
