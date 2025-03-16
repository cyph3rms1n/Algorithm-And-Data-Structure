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
////////////////////////////////////////////////////////////////
// 1st Approach: first reverse the linked list then find the sum for new linked list.
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = reverseLL(l1);
        ListNode* L2 = reverseLL(l2);

        int sum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();

        while (L1 != nullptr || L2 != nullptr) {
            if (L1) {
                sum += L1->val;
                L1 = L1->next;
            }
            if (L2) {
                sum += L2->val;
                L2 = L2->next;
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
///////////////////////////////////////////////////////////////////////////
// 2nd Approach: Withouth reversing the linked List. Using stacks
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
////////////////////////////////////////////////////////////////////////
