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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        if(!head->next){
            return head;
        }
        ListNode* newH = new ListNode(501, head);
        ListNode* nodeBLeft;
        ListNode* leftN;
        ListNode* rightN;
        ListNode* nodeARight;
        ListNode* prev = nullptr;
        ListNode* curr = newH;
        ListNode* next;
        
        //Get the listToRevert
        int count = 0;
        while(curr){
            next = curr->next;
            
            if(count == left){
                leftN = curr;
                nodeBLeft = prev;
            }
            else if(count == right){
                rightN = curr;
                nodeARight = next;
                break;
            }
            
            prev = curr;
            curr = next;
            count++;
        }
        
        curr = leftN;
        
        //cout << leftN->val << endl;
        //cout << "right " << rightN->val << endl;
        prev = nodeARight;
        
        while(curr != rightN){
            //cout << curr->val << endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        //cout << prev->val << endl;
        rightN->next = prev;
        nodeBLeft->next = rightN;
        
        return newH->next;
        
    }
};