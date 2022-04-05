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
    int result = 0;
    int distributeCoins(TreeNode* root) {
        dfsTree(root);
        return result;
    }
    
    int dfsTree(TreeNode* node){
        if(!node){
            return 0;
        }
        
        int leftCount = 0;
        int rightCount = 0;
        
        if(node->left){
            leftCount = dfsTree(node->left);
        }
        
        if(node->right){
            rightCount = dfsTree(node->right);
        }
        
        //The part of tree would need leftCount+rightCount+1 coins
        
        
        result += abs(node->val + leftCount + rightCount - 1);
        return node->val+leftCount+rightCount-1;
    }
};