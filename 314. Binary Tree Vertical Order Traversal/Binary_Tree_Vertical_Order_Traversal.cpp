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
    struct VNode{
        TreeNode* tNode;
        int pos;
        
        VNode(TreeNode* node, int x){
            tNode = node;
            pos = x;
        }
    };
    
    unordered_map<int, vector<int>> posContains;
    int maxPos = 0; 
    int minPos = 0;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        bfsNode(root);
        
        for(int i = minPos; i <= maxPos; i++){
            result.push_back(posContains[i]);
        }
        
        return result;
    }
    
    void bfsNode(TreeNode* root){
        queue<VNode*> nodeQ;
        VNode* rootV = new VNode(root, 0);
        nodeQ.push(rootV);
        VNode* ptr;
        VNode* lPtr;
        VNode* rPtr;
        
        while(!nodeQ.empty()){
            ptr = nodeQ.front();
            nodeQ.pop();
            posContains[ptr->pos].push_back(ptr->tNode->val);
            maxPos = max(maxPos, ptr->pos);
            minPos = min(minPos, ptr->pos);
            if(ptr->tNode->left != NULL){
                lPtr = new VNode(ptr->tNode->left, ptr->pos-1);
                nodeQ.push(lPtr);
            }
            if(ptr->tNode->right != NULL){
                rPtr = new VNode(ptr->tNode->right, ptr->pos+1);
                nodeQ.push(rPtr);
            }
        }
    }
};