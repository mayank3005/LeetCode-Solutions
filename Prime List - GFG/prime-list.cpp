//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{

public:

    Node *primeList(Node *head){

        Node *temp=head;

        while(temp!=NULL)

        {

            int data=temp->val;

            if(data==1)temp->val=2;

            else{

            //we can have two answers now

            //.calculation first one

            int temp1=data,temp2=data;

            int prime1=0,prime2=0;

            while(true)

            {

                int ct=0;

                for(int i=2;i*i<=temp1;i++)

                if(temp1%i==0)ct++;

                if(ct==0){prime1=temp1;break;}

                temp1--;

            }

            while(true)

            {

                int ct=0;

                for(int i=2;i*i<=temp2;i++)

                if(temp2%i==0)ct++;

                if(ct==0){prime2=temp2;break;}

                temp2++;

            }

            

            temp->val=abs(prime1-data)>abs(prime2-data)?prime2:prime1;

            temp=temp->next;

        }}

        return head;

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends