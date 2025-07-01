class Solution {
public:
    //METHOD-2
    //Sorting only..
    //TC= O(NLOGN + 2^N)
    void solve(int i,vector<int>&curr,vector<int>& nums,int tar,vector<vector<int>>&ans)
    {
        if(tar==0)
        {
            ans.push_back(curr);
            return;
        }
        if(i>=nums.size() || tar<0)
        {
            return;
        }

        curr.push_back(nums[i]);
        //we should not like to have repetition..
        solve(i+1,curr,nums,tar-nums[i],ans);
        curr.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1])
        {
            i++;
        }
            
        solve(i+1,curr,nums,tar,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) 
    {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        solve(0,curr,nums,tar,ans);
        return ans;
    }
};
/*
    //METHOD-1
    // Set + Sorting
    //TLE..
    //TC= O(NLOGN + 2^N + N*(2^N))
    void solve(int i,vector<int>&curr,vector<int>& nums,int tar,set<vector<int>>&st)
    {
        if(i>=nums.size())
        {
            if(tar==0)
            {
                st.insert(curr);
            }
            return;
        }
        if(nums[i]<=tar)
        {
            curr.push_back(nums[i]);
            //we should not like to have repetition
            solve(i+1,curr,nums,tar-nums[i],st);
            curr.pop_back();
        }
        solve(i+1,curr,nums,tar,st);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) 
    {
        sort(nums.begin(),nums.end());
        vector<int>curr;

        set<vector<int>>st;
        solve(0,curr,nums,tar,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
*/