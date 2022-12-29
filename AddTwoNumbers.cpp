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

        ListNode* ans = NULL;
        ListNode* prev = NULL;
        int c = 0;

        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + c;

            ListNode* temp = new ListNode(sum % 10);

            c = sum / 10;

            if(ans == NULL) {
                ans = temp;
                prev = ans;
            } else {
                prev->next = temp;
                prev = temp;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            int sum = l1->val + c;

            ListNode* temp = new ListNode(sum % 10);

            c = sum / 10;

            prev->next = temp;
            prev = temp;

            l1 = l1->next;
        }

        while(l2 != NULL) {
            int sum = l2->val + c;

            ListNode* temp = new ListNode(sum % 10);

            c = sum / 10;

            prev->next = temp;
            prev = temp;

            l2 = l2->next;
        }

        if(c == 1) {
            prev->next = new ListNode(1);
        }

        return ans;
    }
};
