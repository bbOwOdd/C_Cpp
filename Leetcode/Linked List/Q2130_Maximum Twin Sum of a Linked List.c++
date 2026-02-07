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
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        int left = 0, right = n - 1;
        for(int i = 0; i < n / 2; i++){
            int sum = nums[left] + nums[right];
            ans = max(ans, sum);
            left++;
            right--;
        }

        return ans;
    }
};
