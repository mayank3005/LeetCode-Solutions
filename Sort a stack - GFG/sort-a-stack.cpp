//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);return;
    }
    int temp=st.top();
    if(temp>ele) st.pop();
    else {st.push(ele);return;}
    insert(st,ele);
    st.push(temp);
    
}

void SortedStack :: sort()
{
   //Your code here
    if(s.empty()) return;
    int ele=s.top();s.pop();
    sort();
    insert(s,ele);
}