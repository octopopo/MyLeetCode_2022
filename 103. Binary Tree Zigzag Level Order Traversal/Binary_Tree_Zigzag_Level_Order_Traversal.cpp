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
    vector<vector<int>> result;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return result;
        }
        TraverseNode(root);
        return result;
    }
    
    void TraverseNode(TreeNode* root){
        stack<TreeNode*>* singleLevel = new stack<TreeNode*>();
        singleLevel->push(root);
        bool isLeftFirst = true;
        
        while(!singleLevel->empty()){
            int sL = singleLevel->size();
            vector<int> currentV(sL, 0);
            stack<TreeNode*>* newLevel = new stack<TreeNode*>();
            for(int i = 0; i < sL; i++){
                TreeNode* currentNode;
                currentNode = singleLevel->top();
                singleLevel->pop();
                currentV[i] = currentNode->val;
                if(isLeftFirst){
                    if(currentNode->left != NULL){
                        newLevel->push(currentNode->left);
                    }
                    if(currentNode->right != NULL){
                        newLevel->push(currentNode->right);
                    }
                }
                else{
                    if(currentNode->right != NULL){
                        newLevel->push(currentNode->right);
                    }
                    if(currentNode->left != NULL){
                        newLevel->push(currentNode->left);
                    }
                }
            }
            isLeftFirst = !isLeftFirst;
            result.push_back(currentV);
            singleLevel = newLevel;
        }
        return;
    }
};