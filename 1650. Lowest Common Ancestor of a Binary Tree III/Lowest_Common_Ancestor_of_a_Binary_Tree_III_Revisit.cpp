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
    bool isChild(Node* node, Node* target){
        if(node == nullptr){
            return false;
        }
        
        if(node == target){
            return true;
        }
        
        bool leftResult = isChild(node->left, target);
        bool rightResult = isChild(node->right, target);
        
        return leftResult || rightResult;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        //Check if p or q is root
        if(!p->parent){
            return p;
        }
        
        if(!q->parent){
            return q;
        }
        //Check if q is p's child
        if(isChild(p, q)){
            return p;
        }
        
        //Check if p is q's child
        if(isChild(q, p)){
            return q;
        }
        
        Node* lastNode = p;
        Node* currentNode;
        
        //if both requirements not met, go above
        while(lastNode->parent){
            currentNode = lastNode->parent->left == lastNode ? lastNode->parent->right : lastNode->parent->left;
            if(isChild(currentNode, q)){
                return lastNode->parent;
            }
            lastNode = lastNode->parent;
        }
        
        return lastNode;
    }
};