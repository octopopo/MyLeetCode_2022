/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        dive(root);
        
        return root;
    }
    
    void dive(Node* root){
        queue<Node*> nodeQueue;
        Node* ptr;
        nodeQueue.push(root);
        int count = 1;
        int layer = 2;
        while(!nodeQueue.empty()){
            ptr = nodeQueue.front();
            nodeQueue.pop();
            if(ptr->left){
                nodeQueue.push(ptr->left);
                nodeQueue.push(ptr->right);
            }
            if(count >= layer-1){
                ptr->next = NULL;
                layer *= 2;
            }
            else{
                ptr->next = nodeQueue.front();
            }
            count++;
        }
    }
};