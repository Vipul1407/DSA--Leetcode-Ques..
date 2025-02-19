class Solution {
public:
    //METHOD-1
    // SWAP + BACKTRACKING...
    void solve(int idx, vector<int>& nums, set<vector<int>>&st)
    {
        if(idx>=nums.size())
        {
            st.insert(nums);
            return;
        }
        //i will start from idx..
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,st);

            //backtracking..
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n= nums.size();
        set<vector<int>>st;
        vector<vector<int>>ans;
        solve(0,nums,st);
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};