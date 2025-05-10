class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1=0,sum2=0,c1=0,c2=0;
        for(int ele:nums1)
        {
            if(ele==0) c1++;
            sum1+=ele;
        }
        for(int ele:nums2)
        {
            if(ele==0) c2++;
            sum2+=ele;
        }
        // sum1=6 c1=2 and sum2=11, c2=1
        if(c1==0 && sum1<sum2+c2) return -1;
        if(c2==0 && sum2<sum1+c1) return -1;

        return max(sum1+c1,sum2+c2);
    }
};