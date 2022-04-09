class HitCounter {
public:
    class Node{
        public:
        int timeStamp;
        int HitCount;
        
        Node* next;
        Node* prev;
    };
    
    unordered_map<int, Node*>timeStampToNode;
    Node* head;
    Node* tail;
    HitCounter() {
        head = new Node();
        head->timeStamp = 0;
        tail = new Node();
        tail->timeStamp = INT_MAX;
        
        head->next = tail;
        tail->prev = head;
    }
    
    void AddNode(int time){
        Node* node = new Node();
        node->timeStamp = time;    
        node->HitCount = 1;
        timeStampToNode[time] = node;
        InsertFromTail(node);
    }
    
    void InsertFromTail(Node* node){
        Node* ptr = tail;
        while(ptr->timeStamp > node->timeStamp){
            ptr = ptr->prev;
        }
        
        
        
        Node* next = ptr->next;
        ptr->next = node;
        node->prev = ptr;
        next->prev = node;
        node->next = next;
    }
    
    void PopFromHead(int time){
        Node* ptr = head->next;
        Node* next;
        int border = time - 300;
        
        
        while(ptr->timeStamp <= border){
            next = ptr->next;
            timeStampToNode.erase(ptr->timeStamp);
            ptr = next;
        }
        head->next = ptr;
        ptr->prev = head;
    }
    
    void hit(int timestamp) {
        if(timeStampToNode.count(timestamp)){
            timeStampToNode[timestamp]->HitCount++;
        }
        else{
            AddNode(timestamp);
        }
    }
    
    int getHits(int timestamp) {
        PopFromHead(timestamp);
        
        Node* ptr = head;
        int sum = 0;
        while(ptr != nullptr){
            sum += ptr->HitCount;
            ptr = ptr->next;
        }
        
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */