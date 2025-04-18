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
//////////////////////////////////////////////////////////////
// 1st Approach: Random Function : rand()  
class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom() {
        int n = arr.size();
        int random = rand() % n;
        return arr[random];
    }
};
/////////////////////////////////////////////////////////////////////////
// 2nd Approach: Reservoir Sampling
class Solution {
public:
    ListNode* Head;
    Solution(ListNode* head) { Head = head; }

    int getRandom() {
        int count = 1;
        int result = 0;

        ListNode* temp = Head;
        while (temp) {
            if (rand() % count < 1.0 / count) {
                result = temp->val;
            }
            count++;
            temp = temp->next;
        }
        return result;
    }
};
/////////////////////////////////////////////////////////////////////////
