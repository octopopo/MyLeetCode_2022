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
    ListNode* reserveList(ListNode* node){
        if(node == nullptr || node->next == nullptr){
            return node;
        }
        ListNode* prev; 
        ListNode* ptr;
        ListNode* next;
        ptr = node;
        
        while(node){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast;
        ListNode* slow;
        ListNode* prev;
        fast = head;
        slow = head;
        
        int maxSum = 0;
        //This way the slow node is at the middle point of the list
        while(slow != nullptr && fast != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* reverseHead = reserveList(slow);
        ListNode* ptr = head;
        ListNode* rPtr = reverseHead;
        prev->next = nullptr;
        while(ptr != nullptr && rPtr != nullptr){
            int tempSum = ptr->val + rPtr->val;
            maxSum = max(maxSum, tempSum);
            ptr = ptr->next;
            rPtr = rPtr->next;
        }
        return maxSum;
    }
};