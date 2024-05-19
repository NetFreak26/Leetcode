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
/**
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* ans = NULL;
        ListNode* curr = NULL;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                if (ans == NULL) {
                    ans = list1;
                    curr = list1;
                } else {
                    curr->next = list1;
                    curr = curr->next;
                }
                list1 = list1->next;
            } else {
                if (ans == NULL) {
                    ans = list2;
                    curr = list2;
                } else {
                    curr->next = list2;
                    curr = curr->next;
                }
                list2 = list2->next;
            }
        }
        if (list1 != NULL) {
            curr->next = list1;
        }
        if (list2 != NULL) {
            curr->next = list2;
        }
        return ans;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }
        ListNode* head = lists[0];
        for (int i=1; i<k; i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }

*/

private:
    struct CompareListNode {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min heap based on ListNode value
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for (int i=0; i<k; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* ans = NULL;
        ListNode* curr = NULL;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (ans == NULL) {
                ans = node;
                curr = node;
            } else {
                curr->next = node;
                curr = node;
            }

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        return ans;
    }
};
