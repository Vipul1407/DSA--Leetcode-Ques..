class Solution {
public:
    void solve(int start, int sum, vector<int>&temp, int k, int &tar, vector<vector<int>>&ans)
    {
        if(sum>tar || k<0)
        {
            return;
        }
        if(sum==tar && k==0)
        {
            ans.push_back(temp);
        }
        for(int i=start;i<10;i++)
        {
            temp.push_back(i);
            //will pass i+1 as we want only unique elements...
            solve(i+1,sum+i,temp,k-1,tar,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int tar) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, 0, temp, k, tar, ans);
        return ans;
    }
};
/*
// METHOD-1
// Without using For Loop..
void solve(int start, int sum, vector<int> &temp, int k, int &tar, vector<vector<int>> &ans)
{
    if (sum > tar || k < 0)
    {
        return;
    }
    if (sum == tar && k == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (start > 9)
    {
        return;
    }
    temp.push_back(start);
    // we will increment start here to ensure that each element occurrs atmost once..
    // so need to take freq vector..
    solve(start + 1, sum + start, temp, k - 1, tar, ans);
    // backtracking...
    temp.pop_back();

    solve(start + 1, sum, temp, k, tar, ans);
}
vector<vector<int>> combinationSum3(int k, int tar)
{
    vector<vector<int>> ans;
    vector<int> temp;

    solve(1, 0, temp, k, tar, ans);
    return ans;
}
*/