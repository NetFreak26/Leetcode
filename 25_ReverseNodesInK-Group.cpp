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
private:
    ListNode* reverseKGroupList(ListNode* node, int l, int k, int i) {
        if (i + k > l) {
            return node;
        }
        ListNode* curr = node;
        ListNode* prev = NULL;
        for (int j=1; j<=k; j++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        node->next = reverseKGroupList(curr, l, k, i+k);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL) {
            return head;
        }
        int l = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            l++;
            curr = curr->next;
        }
        return reverseKGroupList(head, l, k, 0);
    }
};
