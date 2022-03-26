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
    stack<Node*> pAn;
    stack<Node*> qAn;
    Node* lowestCommonAncestor(Node* p, Node * q) {
        goingUp(p, pAn);
        goingUp(q, qAn);
        Node* share;
        Node* pPtr;
        Node* qPtr;
        
        while(!pAn.empty() && !qAn.empty()){
            pPtr = pAn.top();
            qPtr = qAn.top();
            if(qPtr == pPtr){
                share = pPtr;
            }
            else{
                break;
            }
            pAn.pop();
            qAn.pop();
        }
        
        return share;
    }
    
    void goingUp(Node* node, stack<Node*>& nStack){
        Node* temp = node;
        while(temp){
            nStack.push(temp);
            temp = temp->parent;
        }
    }
};