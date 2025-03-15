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
    vector<int> temp_arr;
    int pairSum(ListNode* head) {
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
// 2nd Approach:
