class Solution {
public:
    string convert(string s, int num) {
        
        if(num==1) return s;
        
        map<int,vector<char>> mp;
        
        bool inc=true;
        
        int val=0;
        
        for(int i=0;i<s.size();i++){
            if(inc){
                mp[val].push_back(s[i]);
                val++;
                if(val==num) val=num-2,inc=false;
            }else{
                mp[val].push_back(s[i]);
                val--;
                if(val==-1) val=1,inc=true;
            }
        }
        
        string ans="";
        for(auto &[_,x]:mp){
            for(auto i:x) ans.push_back(i);
        }
        
        return ans;
    }
};