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
    int n; ListNode *tempHead;
    Solution(ListNode* head) {
        srand(time(0));n=0;
        tempHead=head;
        while(head){
            n++,head=head->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%n;
        ListNode *head=tempHead;
        while(head->next and idx--){
            head=head->next;
        }
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */