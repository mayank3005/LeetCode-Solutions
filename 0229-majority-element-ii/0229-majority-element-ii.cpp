class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int num1=-1,num2=-1,c1=0,c2=0;

        for(auto i:v){
            if(i==num1) c1++;
            else if(i==num2) c2++;
            else if(c1==0) num1=i,c1=1;
            else if(c2==0) num2=i,c2=1;
            else c1--,c2--;
        }

        c1=0,c2=0;

        for(auto i:v){
            if(i==num1) c1++;
            else if(i==num2) c2++;
        }

        int n=v.size();
        vector<int> ans;
        
        if(c1>n/3) ans.push_back(num1);
        if(c2>n/3) ans.push_back(num2);
        return ans;
    }
};