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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        ListNode* ptr;
        int whichList = -1;
        int lL = lists.size();
        int minVal = 0;
        
        while(cur != nullptr){
            minVal = INT_MAX;
            whichList = -1;
            for(int i = 0; i < lL; i++){
                if(lists[i] != nullptr){
                    if(lists[i]->val < minVal){
                        minVal = lists[i]->val;
                        whichList = i;
                    }
                }
            }
            
            if(whichList != -1){
                cur->next = lists[whichList];
                lists[whichList] = lists[whichList]->next;
            }
            else{
                break;
            }
            
            cur = cur->next;
        }
        
        return head->next;
    }
};