class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(begin(nums),end(nums));
        int ans= INT_MAX;
        int l=0;
        int r=k-1;
        while(r<nums.size())
        {
            ans= min(ans, nums[r]-nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};