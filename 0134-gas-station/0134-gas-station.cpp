class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(accumulate(cost.begin(),cost.end(),0)>accumulate(gas.begin(),gas.end(),0))
            return -1;
        
        int remFuel=0;int ans=0;
        for(int i=0;i<gas.size();i++){
            remFuel+=gas[i]-cost[i];
            if(remFuel<0){
                ans=i+1;
                remFuel=0;
            }
        }
        return ans;
    }
};