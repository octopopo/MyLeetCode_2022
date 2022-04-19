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
    static bool compare(ListNode* a, ListNode* b){
        if(!a){
            return false;
        }
        
        if(!b){
            return true;
        }
        
        return a->val < b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int heap = 0;
        int remainList;
        int lL = lists.size();
        
        if(lL == 0){
            return nullptr;
        }
        sort(lists.begin(), lists.end(), compare);
        
        for(int i = lL-1; i >= 0; i--){
            if(lists[i]){
                remainList = i;
                break;
            }
        }
        
        while(lists[heap] != nullptr){
            cur->next = lists[heap];
            //cout << lists[heap]->val << endl;
            lists[heap] = lists[heap]->next;
            cur = cur->next;
            if(lists[heap] == nullptr){
                heap++;
                if(heap > remainList){
                    break;
                }
                continue;
            }
            sort(lists.begin()+heap, lists.begin()+remainList+1, compare);

        }
        
        return head->next;
    }
};