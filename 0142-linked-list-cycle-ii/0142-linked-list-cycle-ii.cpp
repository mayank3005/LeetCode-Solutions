/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        bool flag=false;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) {flag=true;break;}
        }
        if(!flag) return NULL;
        while(head!=fast) head=head->next,fast=fast->next;
        return head;
    }
};