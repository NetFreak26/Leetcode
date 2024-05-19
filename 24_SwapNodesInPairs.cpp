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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ans = NULL;
        ListNode* curr = NULL;

        while (head != NULL && head->next != NULL) {
            ListNode* next = head->next;
            head->next = next->next;
            next->next = head;

            if (ans == NULL) {
                ans = next;
            } else {
                curr->next = next;
            }
            curr = head;
            head = head->next;
        }
        return ans;
    }
};
