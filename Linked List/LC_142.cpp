/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
////////////////////////////////////////////////////
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }
        if (slow != fast) return nullptr;

        ListNode* p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return slow;
    }
};
//////////////////////////////////////////////////////
