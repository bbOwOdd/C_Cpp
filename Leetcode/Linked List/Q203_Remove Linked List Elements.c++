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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *next = NULL, *prev = NULL;
        ListNode *current = head;

        while(current != NULL){
            if(current->val == val){
                if(prev == NULL){
                    current = current->next;
                    head = current;
                }else{
                    next = current->next;
                    prev->next = next;
                    current = next;
                }
            }else{
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};
