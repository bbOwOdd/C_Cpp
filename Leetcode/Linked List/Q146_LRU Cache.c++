class LRUCache {
public:
    struct ListNode{
        int key, val;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int val):
        key(key), val(val), prev(NULL), next(NULL){}
    };

    int size;
    int capacity;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> cache;

    void removeNode(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(ListNode* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity): size(0), capacity(capacity) 
    {
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.contains(key)) return -1;
        ListNode* current = cache[key];
        removeNode(current);
        addToHead(current);
        return current->val;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
            ListNode* current = cache[key];
            removeNode(current);
            current->val = value;
            addToHead(current);
        }else{
            ListNode* newNode = new ListNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            if(++size > capacity){
                newNode = tail->prev;
                cache.erase(newNode->key);
                removeNode(newNode);
                --size;
            }
        }
    }
};
