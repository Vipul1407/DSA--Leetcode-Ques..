class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ans=1;
        int cnt=0;
        int maxi= *max_element(nums.begin(),nums.end());
        for(auto i:nums)
        {
            if(i==maxi)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }
            ans= max(ans,cnt);
        }
        return ans;
    }
};