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
    ListNode* reverse(ListNode *head,int n){
        if(n==1){
            return head;
        }
        reverse(head->next,n-1)->next=head;
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *beg=new ListNode(-1);
        beg->next=head;
        ListNode *temp=head;int n=1;
        while(n<left){
            temp=temp->next;n++;
        }
        
        ListNode *lft=temp,*rt=temp;
        while(n<right){
            rt=rt->next;n++;
        }
        if(left==1) head=rt;
        ListNode *end=rt->next;      
        reverse(lft,right-left+1);
        
        while(beg->next!=lft) beg=beg->next;
        beg->next=rt;
        lft->next=end;
        
        return head;
    }
};