/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* findFromChildren(Node* node){
        if(node->left){
            return findFromChildren(node->left);
        }
        return node;
    }
    
    Node* findFromParent(Node* node, int val){
        if(node->val > val){
            //cout << node->val << " " << val << endl;
            return node;
        }
        
        if(!node->parent){
            return nullptr;
        }
        
        return findFromParent(node->parent, val);
    }
    Node* inorderSuccessor(Node* node) {
        if(node->right){
            return findFromChildren(node->right);
        }
        
        
        if(node->parent){
            return findFromParent(node->parent, node->val);
        }
        
        return nullptr;
    }
};