class MinStack {
public:
    class Node{
        public:
        int val;
        Node* next;
        Node* nextMin;
    };
    Node* head;
    Node* minN;
    MinStack() {
        head = new Node();
        head->val = INT_MAX;
        minN = head;
    }
    
    void insertFromHead(int val){
        Node* nNode = new Node();
        nNode->val = val;
        if(val <= minN->val){
            nNode->nextMin = minN;
            minN = nNode;
        }
        else{
            nNode->nextMin = minN;
        }
        
        nNode->next = head->next;
        head->next = nNode;
    }
    
    void popFromHead(){
        Node* pNode = head->next;
        head->next = pNode->next;
        minN = pNode->nextMin;
    }
    
    void push(int val) {
        insertFromHead(val);
    }
    
    void pop() {
        popFromHead();
    }
    
    int top() {
        return head->next->val;
    }
    
    int getMin() {
        return minN->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */