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
   ListNode* doubleIt(ListNode* h) {
    h = h->val > 4 ? new ListNode(0, h) : h;
    for (auto p = h; p != nullptr; p = p->next)
        p->val = (p->val * 2) % 10 + (p->next && p->next->val > 4);
    return h;
}
};