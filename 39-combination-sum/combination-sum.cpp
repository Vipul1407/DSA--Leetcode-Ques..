class Solution {
public:
    // METHOD-2
    // BACKTRACKING..
    // Using For Loop..
    void solve(int i,int sum, vector<int>&temp, int &k, vector<int>&cand, vector<vector<int>>&ans)
    {
        if(sum>k || i>=cand.size())
        {
            return;
        }
        if(sum==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<cand.size();j++)
        {
            temp.push_back(cand[j]);
            solve(j,sum+cand[j],temp,k,cand,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int k) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,0,temp,k,cand,ans);
        return ans;
    }
};
/*
// METHOD-1
// BACKTRACKING..
// Without using for loop...
void solve(int i, int sum, vector<int> &temp, int &k, vector<int> &cand, vector<vector<int>> &ans)
{
    if (sum == k)
    {
        ans.push_back(temp);
        return;
    }
    if (i >= cand.size() || sum > k)
    {
        return;
    }
    temp.push_back(cand[i]);
    // include..
    solve(i, sum + cand[i], temp, k, cand, ans);
    temp.pop_back();
    // exclude..
    solve(i + 1, sum, temp, k, cand, ans);
}
vector<vector<int>> combinationSum(vector<int> &cand, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, 0, temp, k, cand, ans);
    return ans;
}
*/