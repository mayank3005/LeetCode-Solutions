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
    
    ListNode* swapPairs(ListNode* head) {
        
        if(!head or !head->next) return head;
        
        ListNode *f=head,*s=head->next;
        f->next=swapPairs(s->next);
        s->next=f;
        
        return s;
    }
};