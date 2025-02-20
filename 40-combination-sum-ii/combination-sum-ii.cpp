class Solution {
public:
    //METHOD-2
    // Without For Loop.. + Freq(used) vector..
    void solve(int i, int sum, vector<int>&used,vector<int>&temp, vector<int>&cand, int k, vector<vector<int>>&ans)
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
        if(used[cand[i]]==0)
        {
            //call exclude case when i cannot have that freq.
            solve(i+1,sum,used,temp,cand,k,ans);
            return;
        }
       
        //include case..
        used[cand[i]]--;
        temp.push_back(cand[i]);
        solve(i,sum+cand[i],used,temp,cand,k,ans);

        //backtracking..
        temp.pop_back();
        used[cand[i]]++;
        //do this extra thing to prevent traversing the same recursive tree again.. before this we must sort cand array
        while(i+1<cand.size() && cand[i]==cand[i+1])
        {
            i++;
        }
        //exclude case..
        solve(i+1,sum,used,temp,cand,k,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int k) 
    {
        vector<vector<int>>ans;
        //must step...
        sort(cand.begin(),cand.end());
        vector<int>temp;
        vector<int>used(51,0);
        for(auto i:cand)
        {
            used[i]++;
        }
        solve(0,0,used,temp,cand,k,ans);
        return ans;
    }
};
/*
// METHOD-1
// Using For Loop.. + Freq(used) vector
// BACKTRACKING..
void solve(int i, int sum, vector<int> &used, vector<int> &temp, vector<int> &cand, int k, vector<vector<int>> &ans)
{
    if (sum > k || i >= cand.size())
    {
        return;
    }
    if (sum == k)
    {
        ans.push_back(temp);
        return;
    }
    // include case..
    for (int j = i; j < cand.size(); j++)
    {
        if (used[cand[j]] == 0)
        {
            continue;
        }
        used[cand[j]]--;
        temp.push_back(cand[j]);
        solve(j, sum + cand[j], used, temp, cand, k, ans);

        // backtracking..
        temp.pop_back();
        used[cand[j]]++;

        // do this extra thing to prevent traversing the same recursive tree again.. before this we must sort cand array
        while (j + 1 < cand.size() && cand[j] == cand[j + 1])
        {
            j++;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &cand, int k)
{
    vector<vector<int>> ans;
    // must step...
    sort(cand.begin(), cand.end());
    vector<int> temp;
    vector<int> used(51, 0);
    for (auto i : cand)
    {
        used[i]++;
    }
    solve(0, 0, used, temp, cand, k, ans);
    return ans;
}
*/