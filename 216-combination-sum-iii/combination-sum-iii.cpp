class Solution {
public:
    void solve(int i,int &k,int tar,vector<int> &curr,vector<vector<int>> &ans)
    {
        if (tar < 0 || curr.size()>k)
        {
            return;
        }
        if(tar == 0 && curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        if(i>9)
        {
            return;
        }

        curr.push_back(i);
        // we should not like to have repetition..
        solve(i + 1, k, tar - i, curr, ans);
        curr.pop_back();

        solve(i + 1,  k, tar, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int tar) 
    {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(1,k,tar,curr,ans);
        return ans;
    }
};