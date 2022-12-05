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
    ListNode* middleNode(ListNode* head) {
        if(!head or !head->next) return head;
        int sz=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            sz++;
        }
        temp=head;
        for(int i=0;i<sz/2;i++){
            temp=temp->next;
        }
        return temp;
    }
};