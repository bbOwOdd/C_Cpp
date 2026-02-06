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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* current = head;
        while(current){
            nums.push_back(current->val);
            current = current->next;
        }
        sort(nums.begin(), nums.end());

        current = head;
        for(auto n : nums){
            current->val = n;
            current = current->next;
        }

        return head;
    }
};
