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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (prev != NULL) {
            ListNode* current = prev;
            for (int i = 0; i < k; i++) {
                current = current->next;
                if (current == NULL) return dummy->next;
            }

            ListNode* node = prev->next;
            ListNode* next = current->next;
            current->next = NULL;
            prev->next = reverse(node);
            node->next = next;
            prev = node;
        }
        return dummy->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL, *next = NULL;
        ListNode* current = head;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
