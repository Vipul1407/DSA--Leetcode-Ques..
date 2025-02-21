class Solution {
public:
    void solve(int start,int sum, vector<int>&temp, int k, int &tar, vector<vector<int>>&ans)
    {
        if(sum>tar || k<0)
        {
            return;
        }
        if(sum==tar && k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(start>9)
        {
            return;
        }
        temp.push_back(start);
        //we will increment start here to ensure that each element occurrs atmost once..
        solve(start+1,sum+start,temp,k-1,tar,ans);
        //backtracking...
        temp.pop_back();
        
        solve(start+1,sum,temp,k,tar,ans);
    }
    vector<vector<int>> combinationSum3(int k, int tar) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(1,0,temp,k,tar,ans);
        return ans;
    }
};