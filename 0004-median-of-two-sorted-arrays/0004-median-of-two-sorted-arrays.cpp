class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int n1=nums1.size(),n2=nums2.size();
        int l=0,r=nums1.size();
        while(l<=r){
            int cut1=(l+r)>>1;
            int cut2=(n1+n2)/2-cut1;
            
            int l1,l2,r1,r2;
            l1=l2=INT_MIN,r1=r2=INT_MAX;
            if(cut1) l1=nums1[cut1-1];
            if(cut2) l2=nums2[cut2-1];
            if(cut1!=n1) r1=nums1[cut1];
            if(cut2!=n2) r2=nums2[cut2]; 
            
            if(l1<=r2 and l2<=r1){
                if((n1+n2)&1) return 1.0*min(r1,r2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            
            if(l1>r2) r=cut1-1;
            else l=cut1+1;
            
        }
        return 0.0;
    }
};