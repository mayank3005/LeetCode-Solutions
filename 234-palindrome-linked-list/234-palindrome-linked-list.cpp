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
    ListNode* reverseList(ListNode* head) {
        ListNode *one = NULL,*two = head,*three=head;
        while(three){
            three=three->next;
            two->next=one;
            one=two;
            two=three;
        }
        return one;
    }
    bool isPalindrome(ListNode* head) {
        int sz=0;
        ListNode *temp=head;
        while(temp) temp=temp->next,sz++;
        if(sz==1) return true;
        ListNode *temp2=head;temp=head;
        for(int i=0;i<sz/2;i++){
            temp2=temp2->next;
        }
        if(sz&1) temp2=temp2->next;
        temp2=reverseList(temp2);
        ListNode *temp21=temp2;
        while(temp2){
            if(temp->val!=temp2->val) return false;
            temp=temp->next;temp2=temp2->next;
        }
        temp2=reverseList(temp21);
        return true;
    }
};