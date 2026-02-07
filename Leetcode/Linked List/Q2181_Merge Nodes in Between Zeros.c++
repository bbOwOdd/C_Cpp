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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        ListNode* current = head->next;
        int sum = 0;
        while(current != NULL){
            if(current->val) sum += current->val;
            else{
                ans->next = new ListNode(sum);
                ans = ans->next;
                sum = 0;
            }
            current = current->next;
        }
        return dummy->next;
    }
};
