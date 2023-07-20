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
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL,*next=head;
        while(next){
            next=next->next;head->next=prev;prev=head;head=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode *slow=head,*fast=head;
        while(fast and fast->next){
            fast=fast->next; if(fast) fast=fast->next;
            slow=slow->next;
        }
        ListNode *sec=head;
        ListNode *rev=reverse(slow); ListNode *start=rev;
        bool check=true;
        while(rev){
            if(rev->val!=sec->val) check=false;
            rev=rev->next;sec=sec->next;
        }
        reverse(start);
        return check;
    }
};