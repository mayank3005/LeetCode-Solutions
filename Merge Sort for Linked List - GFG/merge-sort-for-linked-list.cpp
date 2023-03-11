//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node *merge(Node *root1,Node *root2){
        if(!root1) return root2;
        if(!root2) return root1;
        
        Node *temp;
        
        if(root1->data < root2->data) temp=root1;
        else temp=root2;
        
        if(temp==root1) temp->next=merge(root1->next,root2);
        else temp->next=merge(root1,root2->next);
        return temp;
    }
    
    Node *findMiddle(Node *root){
        if(!root) return root;
        Node *slow=root,*fast=root->next;
        while(fast and fast->next){
            fast=fast->next;
            if(fast) fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !(head->next)) return head;
        Node *middle=findMiddle(head);Node *middleNext=middle->next;
        middle->next=NULL;
        Node *root1=mergeSort(head);
        Node *root2=mergeSort(middleNext);
        return merge(root1,root2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends