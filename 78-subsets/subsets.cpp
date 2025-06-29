class Solution {
public:
    void solve(int i,vector<int>&curr,vector<int>& nums,vector<vector<int>>&ans)
    {
        if(i>= nums.size())
        {
            ans.push_back(curr);
            return;
        }
        //include...
        curr.push_back(nums[i]);
        solve(i+1,curr,nums,ans);
        curr.pop_back();

        //not include...
        solve(i+1,curr,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,nums,ans);
        return ans;
    }
};