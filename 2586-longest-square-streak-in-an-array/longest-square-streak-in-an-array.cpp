class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        //applying binary search...
        int ans=1;
        for(auto i:nums)
        {
            int cnt=1;
            long long curr= i;
            while(curr*curr<=INT_MAX && binary_search(nums.begin(),nums.end(),curr*curr))
            {
                curr*=curr;
                cnt++;
            }
            ans= max(cnt,ans);
        }
        return ans==1? -1:ans;
    }
};