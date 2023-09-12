class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);
        for(auto i:s) freq[i-'a']++;
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int ans=0;
        
        for(int i=1;i<26;i++){
            
            if(!freq[i]) break;
            
            if(freq[i]>=freq[i-1]){
                
                int prev=freq[i];
                freq[i]=max(0,freq[i-1]-1);
                ans+=prev-freq[i];
            }
            
        }
        return ans;
    }
};