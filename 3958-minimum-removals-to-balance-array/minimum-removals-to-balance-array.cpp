class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {
        sort(begin(nums),end(nums));
        int n= nums.size();
        int l=0,r=0,ans=0;
        while(r<n)
        {
            if(l<=r && (long long)nums[r]>(long long)k*nums[l])
            {
                l++;
            }
            ans= max(ans,r-l+1);
            r++;
        }
        return n-ans;
    }
};