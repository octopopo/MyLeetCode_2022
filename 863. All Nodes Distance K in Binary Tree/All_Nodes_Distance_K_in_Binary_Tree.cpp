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
    vector<int> res;
    //first value in is for ancestors nodes, interger was for detemine target is on the left/right of the node
    stack<pair<TreeNode*, int>> ancestors;
    bool goDeepAndFindTarget(TreeNode* target, TreeNode* nodeToCheck){
        bool isTargetFound = false;
        if(nodeToCheck == nullptr){
            return false;
        }
        
        ancestors.push(make_pair(nodeToCheck,0));
        if(nodeToCheck == target){
            return true;
        }
        
        ancestors.top().second = -1;
        isTargetFound = goDeepAndFindTarget(target, nodeToCheck->left);
        if(isTargetFound){
            return true;
        }
        
        ancestors.top().second = 1;
        isTargetFound = goDeepAndFindTarget(target, nodeToCheck->right);
        if(isTargetFound){
            return true;
        }
        
        ancestors.pop();
        return false;
    }
    
    void bfsAndAddNodesWDistance(TreeNode* start, int direction, int distance){
        //cout << start->val << " d: " << direction << " dis: " << distance << endl;
        TreeNode* tPtr;
        queue<TreeNode*> tQ;
        int qSize;
        
        if(distance == 0){
            res.push_back(start->val);
            return;
        }
        
        //either direction is 0 or direction is -1 we should check left child
        if(direction != 1 && start->left){
            tQ.push(start->left);
        }
        
        //either direction is 0 or 1, we should check right child
        if(direction!=-1 && start->right){
            tQ.push(start->right);
        }
        
        //do bfs
        while(!tQ.empty()){
            distance--;
            qSize = tQ.size();
            for(int i = 0; i < qSize; i++){
                tPtr = tQ.front();
                tQ.pop();
                //if reach the distance, add to result vector and no need to check its child
                if(distance == 0){
                    res.push_back(tPtr->val);
                    continue;
                }
                //Not reach the distance yet, keep searching child
                else{
                    if(tPtr->left){
                        tQ.push(tPtr->left);
                    }
                    
                    if(tPtr->right){
                        tQ.push(tPtr->right);
                    }
                }
            }
        }
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bool isTargetFound = false;
        int aL;
        isTargetFound = goDeepAndFindTarget(target, root);
        
        //If not find the target, return
        if(!isTargetFound){
            return res;
        }
        
        //Start with it self, and go up
        aL = ancestors.size();
        pair<TreeNode*, int> tempPair;
        for(int i = aL; i >= 0 && k >= 0 && !ancestors.empty(); i--, k--){
            tempPair = ancestors.top();
            ancestors.pop();
            bfsAndAddNodesWDistance(tempPair.first, -tempPair.second, k);
        }
        
        return res;
    }
};