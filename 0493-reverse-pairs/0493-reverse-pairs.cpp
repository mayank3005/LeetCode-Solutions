class Solution {
public:
    int merge(int st,int en,vector<int> &nums){
        int mid=(st+en)>>1; int inv=0;
        vector<int> temp(en-st+1);
        int i=st,j=mid+1;int k=0;
        while(i<=mid){
            while(j<=en and 1LL*nums[i]>2*1LL*nums[j]){
                j++;
            }
            inv+=(j-mid-1);
            i++;
        }
        i=st,j=mid+1;
        while(i<=mid and j<=en){
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=en) temp[k++]=nums[j++];
        for(int i=0;i<k;i++) nums[st+i]=temp[i];
        return inv;
    }
    int ms(int i,int j,vector<int> &nums){
        if(i>=j) return 0;
        int k=(i+j)>>1;
        int inv=ms(i,k,nums)+ms(k+1,j,nums);
        return inv+merge(i,j,nums);
    }
    int reversePairs(vector<int>& nums) {
        return ms(0,nums.size()-1,nums);
    }
};