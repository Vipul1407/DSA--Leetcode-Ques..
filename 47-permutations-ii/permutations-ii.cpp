class Solution {
public:
    // METHOD-2
    // MAINTAING CNT VECTOR...
    // Here we cannot use USED VECTOR METHOD as here element is not unique..
    void solve(vector<int>curr, vector<int>&cnt, vector<int>& nums, vector<vector<int>>&ans)
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<cnt.size();i++)
        {
            if(cnt[i]==0)
            {
                continue;
            }
            cnt[i]--;
            curr.push_back(i-10);
            solve(curr,cnt,nums,ans);
            curr.pop_back();
            cnt[i]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>cnt(21,0);
        for(auto i:nums)
        {
            cnt[i+10]++;
        }
        vector<int>curr;
        solve(curr,cnt,nums,ans);
        return ans;
    }
};
/*
// METHOD-1
//  SWAP + BACKTRACKING + SET (to avoid duplicate entries)...
// Elements are not unique
void solve(int idx, vector<int> &nums, set<vector<int>> &st)
{
    if (idx >= nums.size())
    {
        st.insert(nums);
        return;
    }
    // i will start from idx..
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        solve(idx + 1, nums, st);

        // backtracking..
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    vector<vector<int>> ans;
    solve(0, nums, st);
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}
*/