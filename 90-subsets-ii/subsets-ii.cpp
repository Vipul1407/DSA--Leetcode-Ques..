class Solution {
public:
    //METHOD-2
    //Using Sorting only..
    void solve(int i,vector<int>&curr,vector<vector<int>>&ans,vector<int>& nums)
    {
        if(i>= nums.size())
        {
            ans.push_back(curr);
            return;
        }
        //include..
        curr.push_back(nums[i]);
        solve(i+1,curr,ans,nums);
        curr.pop_back();

        //skip adjacent same elements before exclude..
        while(i+1<nums.size() && nums[i]==nums[i+1])
        {
            i++;
        }
        
        //exclude..
        solve(i+1,curr,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        solve(0,curr,ans,nums);
        
        return ans;
    }
};
/*
    //METHOD-1
    //Using Unordered-set + sorting
    void solve(int i,vector<int>&curr,set<vector<int>>&st,vector<int>& nums)
    {
        if(i>= nums.size())
        {
            st.insert(curr);
            return;
        }
        //include..
        curr.push_back(nums[i]);
        solve(i+1,curr,st,nums);
        curr.pop_back();

        //exclude..
        solve(i+1,curr,st,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>curr;
        set<vector<int>>st;
        solve(0,curr,st,nums);
        vector<vector<int>>ans(st.begin(),st.end());
        
        return ans;
    }
*/