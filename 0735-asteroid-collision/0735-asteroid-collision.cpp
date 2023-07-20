class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto i:asteroids){
            if(i<0){
                bool check=true;
                while(check){
                    if(ans.empty() or ans.back()<0) break;
                    if(ans.back()==abs(i)) check=false,ans.pop_back();
                    else if(ans.back()<abs(i)) ans.pop_back();
                    else check=false;
                }
                if(check) ans.push_back(i);
            }else{ 
                ans.push_back(i);
            }
        }
        return ans;
    }
};