class LRUCache {
    struct DNode{
        int key;
        int val;
        DNode* next;
        DNode* prev;
    };
public:
    DNode* head;
    DNode* tail;
    int nodeCount;
    int maxCap;
    unordered_map<int, DNode*> keyToNode;
    
    void InsertFromHead(DNode* node){
        DNode* temp = head->next;
        node->next = temp;
        temp->prev = node;
        head->next =  node;
        node->prev = head;
    }
    
    void PopTail(){
        DNode* beforeTail =  tail->prev; 
        //cout << beforeTail->key << endl;
        beforeTail->prev->next = tail;
        tail->prev = beforeTail->prev;
        keyToNode.erase(beforeTail->key);
        delete beforeTail;
    }
    
    DNode* PopTargetKey(int key){
        DNode* targetNode = keyToNode[key];
        
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
        
        return targetNode;
    }
    
    LRUCache(int capacity) {
        head = new DNode();
        tail = new DNode();
        nodeCount = 0;
        
        head->next = tail;
        tail->prev = head;
        maxCap = capacity;
    }
    
    int get(int key) {
        if(keyToNode.count(key)){
            DNode* tempNode = PopTargetKey(key);
            InsertFromHead(tempNode);
            return keyToNode[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //cout << "put" << endl;
        if(keyToNode.count(key)){
            DNode* target = PopTargetKey(key);
            target->val = value;
            InsertFromHead(target);
        }
        else{
            DNode* newNode = new DNode();
            newNode->val = value;
            newNode->key = key;
            keyToNode[key] = newNode;
            InsertFromHead(newNode);
            
            if(nodeCount < maxCap){
                nodeCount++;
            }
            else{
                PopTail();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */