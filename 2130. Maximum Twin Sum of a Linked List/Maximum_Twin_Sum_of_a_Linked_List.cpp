/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int maxSum = 0;
    vector<ListNode*> record;
    int pairSum(ListNode* head) {
        int maxSum = 0;
        ListNode* ptr = head;
        
        //go through whole list and build the vector
        while(ptr != NULL){
            record.push_back(ptr);
            ptr = ptr->next;
        }
        
        int totalNode = record.size();
        int tempSum;
        
        for(int i = 0; i < totalNode/2; i++){
            tempSum = record[i]->val + record[totalNode-1-i]->val;
            maxSum = max(maxSum, tempSum);
        }
        
        return maxSum;
    }
};