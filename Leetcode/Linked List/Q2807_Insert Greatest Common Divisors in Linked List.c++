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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        ListNode* current = head->next;
        while(current != NULL){
            int x = mygcd(pre->val, current->val);
            pre->next = new ListNode(x, current);
            pre = current;
            current = current->next;
        }
        return head;       
    }

    int mygcd(int x, int y){
        return y == 0 ? x : mygcd(y, x % y);
    }
};
