class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        int l=0;
        int r= nums.size()-1;
        int ans= 0;
        while(l<=r)
        {
            ans= max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};