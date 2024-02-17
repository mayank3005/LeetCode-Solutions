class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int val=0;
        priority_queue<int> pq;
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                pq.push(heights[i]-heights[i-1]);
                val+=(heights[i]-heights[i-1]);
                while(val>bricks){
                    if(ladders<=0) return i-1;
                    val-=pq.top();pq.pop();
                    ladders--;
                }
            }
        }
        return heights.size()-1;
    }
};