class DoubleLinkedNode{
public:
    int key;
    int value;    
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;
};

class LRUCache {
public:
    DoubleLinkedNode* head;
    DoubleLinkedNode* tail;
    unordered_map<int, DoubleLinkedNode*> record;
    int size;
    int maxCapacity;
    void addNode(DoubleLinkedNode* node){
        node->next = head->next;
        head->next->prev = node;
        
        head->next = node;
        node->prev = head;
    }
    
    void removeNode(DoubleLinkedNode* node){
        DoubleLinkedNode* prev = node->prev;
        DoubleLinkedNode* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(DoubleLinkedNode* node){
        removeNode(node);
        addNode(node);
    }
    
    DoubleLinkedNode* popTail(){
        DoubleLinkedNode* last = tail->prev;
        removeNode(last);
        return last;
    }
    
    LRUCache(int capacity) {
        maxCapacity = capacity;
        size = 0;
        head = new DoubleLinkedNode();
        tail = new DoubleLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!record.count(key)){
            return -1;
        }
        
        DoubleLinkedNode* temp = record[key];
        moveToHead(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(!record.count(key)){
            DoubleLinkedNode* newNode = new DoubleLinkedNode();
            newNode->key = key;
            newNode->value = value;
            record[key] = newNode;
            addNode(newNode);
            if(size < maxCapacity){
                size++;
                return;
            }
            DoubleLinkedNode* last = popTail();
            record.erase(last->key);
        }
        else{
            DoubleLinkedNode* oldNode = record[key];
            oldNode->value = value;
            moveToHead(oldNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */