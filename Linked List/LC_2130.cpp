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
// 1st Approach: Using Vector
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> temp_arr;
        ListNode* temp = head;
        while (temp) {
            temp_arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = temp_arr.size();
        int i = 0;
        int j = n - 1;
        int result = 0;

        while (i < j) {
            int sum = temp_arr[i] + temp_arr[j];
            result = max(result, sum);
            i++;
            j--;
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////
// 2nd Approach: Using Stack
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        int n = st.size();
        temp = head;
        int result = 0;
        int count = 1;
        while (count <= n / 2) {
            result = max(result, st.top() + temp->val);
            temp = temp->next;
            st.pop();
            count++;
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////
// 3rd Approach: Reversing the 2nd half of the linked list.
class Solution {
public:
    int pairSum(ListNode* head) {
        // 1st Find Mid
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        // 2nd Reverse 2nd half of the Linked List
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        while (mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        // 3. Find Max result
        int result = 0;
        ListNode* curr = head;

        while (prev) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////
