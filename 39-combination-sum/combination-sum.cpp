class Solution {
public:
    void solve(int i,vector<int>&curr,vector<int>& nums, int tar, vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            if(tar==0)
            {
                ans.push_back(curr);
            }
            return;
        }
        if(nums[i]<=tar)
        {
            curr.push_back(nums[i]);
            //will not pass i+1 as we can have repeatitions..
            solve(i,curr,nums,tar-nums[i],ans);
            curr.pop_back();
        }
        solve(i+1,curr,nums,tar,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) 
    {
        int n= nums.size(); 
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,nums,tar,ans);
        return ans;
    }
};