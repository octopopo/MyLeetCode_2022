/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> parentStack;
    bool dfsTreeToFindTarget(TreeNode* node, TreeNode* p){
        if(node == p){
            parentStack.push(node);
            return true;
        }

        bool checkResult = false;
        if(p->val > node->val){
            if(node->right){
                checkResult = dfsTreeToFindTarget(node->right, p);
            }
        }
        else{
            if(node->left){
                parentStack.push(node);
                checkResult = dfsTreeToFindTarget(node->left, p);
            }
            if(!checkResult){
                parentStack.pop();
            }
        }
        
        return checkResult;
    }
    
    TreeNode* findSmallestNode(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        
        if(node->left){
            return findSmallestNode(node->left);
        }
        
        return node;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
            return findSmallestNode(p->right);
        }
        dfsTreeToFindTarget(root, p);
        
        while(!parentStack.empty()){
            if(parentStack.top()->val > p->val){
                return parentStack.top();
            }
            parentStack.pop();
        }
        
        return nullptr;
        
        
        //Find the targetNode, and should have a stack of parent nodes
        
    }
};