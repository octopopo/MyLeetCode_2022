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
    vector<int> res;
    vector<TreeNode*> leftV;
    vector<TreeNode*> rightV;
    vector<int> leafV;
    
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
    
    void dfsTree(TreeNode* node){
        if(isLeaf(node)){
            if(!leftV.empty() && node == leftV.back()){
                leftV.pop_back();
            }
            else if(!rightV.empty() && node == rightV.back()){
                rightV.pop_back();
            }
            leafV.push_back(node->val);
        }
        else{
            if(!leftV.empty() && node == leftV.back()){
                if(node->left){
                    leftV.push_back(node->left);
                }
                else if(node->right){
                    leftV.push_back(node->right);
                }
            }
            if(!rightV.empty() && node == rightV.back()){
                if(node->right){
                    rightV.push_back(node->right);
                }
                else if(node->left){
                    rightV.push_back(node->left);
                }
            }
            if(node->left){
                dfsTree(node->left);
            }
            if(node->right){
                dfsTree(node->right);
            }
        }
    }
    
    
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        res.push_back(root->val);
        
        if(isLeaf(root)){
            return res;
        }
        
        if(root->left){
            leftV.push_back(root->left);
            dfsTree(root->left);
        }
        
        if(root->right){
            rightV.push_back(root->right);
            dfsTree(root->right);
        }
        
        for(TreeNode* l : leftV){
            res.push_back(l->val);
        }
        
        for(int l : leafV){
            res.push_back(l);
        }
        
        for(int i = rightV.size()-1; i>= 0; i--){
            res.push_back(rightV[i]->val);
        }
        
        return res;
    }
};