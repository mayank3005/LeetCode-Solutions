class Solution {
public:
    int hIndex(vector<int>& citations) { 
        sort(citations.begin(),citations.end());
        int n=citations.size();
        if(n==0||citations[n-1]==0){return 0;}
     
      for(int i=0;i<n;i++){ 
         if(n-i-1<citations[i]){
             return n-i;
         }   
      }
       
	   return 0;}
};