/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int lowV, highV;
    int rangeSumBST(TreeNode* root, int low, int high) {
        lowV = low;
        highV = high;
        dfsTree(root);
        
        return sum;
    }
    
    void dfsTree(TreeNode* node){
        if(node == NULL){
            return;
        }
        if(node->val >= lowV && node->val <= highV){
            sum += node->val;
        }
        
        if(node->val > lowV){
            dfsTree(node->left);
        }
        
        if(node->val < highV){
            dfsTree(node->right);
        }
    }
};