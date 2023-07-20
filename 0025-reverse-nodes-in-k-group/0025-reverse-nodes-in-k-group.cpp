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
    ListNode* reverse(ListNode *head,ListNode *last){
        ListNode *prev=NULL,*after=head;
        while(after!=last){
            after=after->next;head->next=prev;prev=head;head=after;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next;
        }
        ListNode *newHead=reverse(head,temp);
        head->next=reverseKGroup(temp,k);
        return newHead;
    }
};