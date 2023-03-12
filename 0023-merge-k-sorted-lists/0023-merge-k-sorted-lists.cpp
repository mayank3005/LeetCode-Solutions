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
   
    ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode* result = NULL;
        
        if(first == nullptr)
            return second;
        
        if(second == nullptr)
            return first;
        
        
        if(first -> val <= second -> val)
        {
            result = first;
            result -> next = merge(first -> next, second);
        }
        else
        {
            result = second;
            result -> next = merge(first, second -> next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int k = arr.size();
        if(k == 0) 
            return NULL;
        
        int start = 0;
        int last = k -1; 
        int temp;
        while(last != 0) 
        {
            start = 0;
            temp = last;
            while(start < temp)
            {

                arr[start] = merge(arr[start],arr[temp]);
                start++; 
                temp--;
                
                if(start >= temp) 
                {
                    last = temp;
                }
            }
        }
        return arr[0]; 
        
    }
};