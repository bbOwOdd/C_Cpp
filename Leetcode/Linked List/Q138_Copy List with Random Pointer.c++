/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        unordered_map<Node*, Node*> map;
        for(Node* current = head; current != NULL; current = current->next){
            Node* node = new Node(current->val);
            tail->next = node;
            tail = node;
            map[current] = node;
        }
        for(Node* current = head; current != NULL; current = current->next){
            map[current]->random = current->random ? map[current->random] : NULL;
        }
        return dummy->next;
    }
};
