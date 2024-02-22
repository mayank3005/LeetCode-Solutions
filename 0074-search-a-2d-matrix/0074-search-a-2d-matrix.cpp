class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m and j>=0){
            int val=matrix[i][j];
            if(val==target) return true;
            else if(val>target) j--;
            else i++;
        }
        return false;
    }
};