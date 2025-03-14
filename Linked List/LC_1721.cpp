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
/////////////////////////////////////////////////////////////////////
// 1st Approach:
class Solution {
public:
    int findLength(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int L = findLength(head);

        int k1 = k;
        ListNode* node1 = head;

        while (k1 > 1) {
            node1 = node1->next;
            k1--;
        }

        int k2 = L - k + 1;
        ListNode* node2 = head;

        while (k2 > 1) {
            node2 = node2->next;
            k2--;
        }

        swap(node1->val, node2->val);
        return head;
    }
};
//////////////////////////////////////////////////////////////////////
// 2nd Approach:
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        ListNode* temp = head;

        while (temp) {
            if (p2 != nullptr) {
                p2 = p2->next;
            }
            k--;

            if (k == 0) {
                p1 = temp;
                p2 = head;
            }
            temp = temp->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};
/////////////////////////////////////////////////////////////////////////
