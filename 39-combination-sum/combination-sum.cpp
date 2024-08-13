class Solution 
{
public:

    vector<vector<int>>ans;
    void solve(int i, vector<int>& cand, int k, vector<int>vec)
    {
        if(k==0)
        {
            ans.push_back(vec);
            return;
        }
        if(i==cand.size() || k<0)
        {
            return;
        }
        //take
        if(cand[i]<=k)
        {
            vec.push_back(cand[i]);
            solve(i,cand,k-cand[i],vec);
            vec.pop_back();
        }
        //not take
        solve(i+1,cand,k,vec);
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int k) 
    {
        vector<int>vec;
        solve(0,cand,k,vec);
        return ans;
    }
};