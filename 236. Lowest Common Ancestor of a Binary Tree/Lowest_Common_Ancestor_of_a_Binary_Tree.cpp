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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* leftR = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightR = lowestCommonAncestor(root->right, p, q);
        
        if(leftR && rightR){
            return root;
        }
        
        if(leftR){
            return leftR;
        }
        
        if(rightR){
            return rightR;
        }
        
        return nullptr;
    }
};