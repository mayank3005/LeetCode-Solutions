class Solution {
public:

    bool satisfy(vector<int>& freq, int k){
        if(freq[0]>=k && freq[1]>=k && freq[2]>=k) return true;
        else return false;
    }

    bool isValid(string s, int k, int ptr){
        vector<int> freq(3, 0);

        for(int i=0; i<ptr; i++){
            freq[s[i]-'a']++;
        }
        if(satisfy(freq, k)) return true;

        int size = s.length();
        int left = ptr-1;
        int right = size-1;

        while(left>=0){
            freq[s[left]-'a']--;
            freq[s[right]-'a']++;
            if(satisfy(freq, k)) return true;
            left--;
            right--;
        }

        return false;

    }

    int takeCharacters(string s, int k) {
        
        int start = 0;
        int end = s.length();
        int ans = INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;

            if(isValid(s, k, mid)){
                ans=mid;
                end = mid-1;
            }else{
                start = mid+1;
            }

        }

        if(ans==INT_MAX) ans = -1; 

        return ans;

    }
};