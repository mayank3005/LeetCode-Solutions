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
    ListNode *rev(ListNode **head_ref,ListNode *head){
        if(!head->next){
            *head_ref=head;
            return head;
        }
        rev(head_ref,head->next)->next=head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode *one = NULL,*two = head,*three=head;
        // while(three){
        //     three=three->next;
        //     two->next=one;
        //     one=two;
        //     two=three;
        // }
        // return one;
        ListNode *temp=head;
        if(head) rev(&temp,head)->next=NULL;
        return temp;
    }
};