/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *temp=head;
        while(temp){
            Node *node=new Node(temp->val);
            node->next=temp->next; temp->next=node;
            temp=temp->next->next;
        }
        Node *head2=head->next;
        temp=head;
        while(temp){
            Node *node=temp->next;
            if(temp->random) node->random=temp->random->next;
            temp=temp->next->next;
        } temp=head;
        while(temp){
            Node *node=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            if(temp) node->next=temp->next;
        }
        return head2;
    }
};