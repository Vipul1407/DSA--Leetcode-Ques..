class Solution {
public:
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
};