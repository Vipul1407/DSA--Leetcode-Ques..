class Solution {
public:
    //METHOD-2
    //USING BACKTRACKING LIKE Ques. Letter Tile Permutation..
    void solve(int len, vector<int>curr, vector<int>& nums, vector<int>&used, vector<vector<int>>&ans)
    {
        if(len==nums.size())
        {
            ans.push_back(curr);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==1)
            {
                continue;
            }
            used[i]=1;
            curr.push_back(nums[i]);
            solve(len+1,curr,nums,used,ans);
            curr.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        vector<int>used(n,0);
        vector<int>curr;
        solve(0,curr,nums,used,ans);
        return ans;    
    }
};

/*
// METHOD-1
// USING NEXT PERMUTATION STL..
vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    // using while loop.....
    ans.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        ans.push_back(nums);
    }
    // using do while loop....
    //  do
    //  {
    //      ans.push_back(nums);
    //  }
    //  while(next_permutation(nums.begin(),nums.end()));
    return ans;
}
*/