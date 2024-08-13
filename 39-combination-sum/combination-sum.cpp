class Solution 
{
public:

    vector<vector<int>>ans;
    void solve(int i, vector<int>& cand, int k, vector<int>vec)
    {
        int n= cand.size();
        if(k==0)
        {
            ans.push_back(vec);
            return;
        }
        if(i==n || k<0)
        {
            return;
        }
        for(int j=i;j<n;j++)
        {
            vec.push_back(cand[j]);
            solve(j,cand,k-cand[j],vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int k) 
    {
        vector<int>vec;
        solve(0,cand,k,vec);
        return ans;
    }
};