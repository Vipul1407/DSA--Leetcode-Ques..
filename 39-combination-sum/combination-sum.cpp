class Solution {
public:
    //METHOD-3
    vector<vector<int>>ans;
    void solve(int i, vector<int>& cand, int k, vector<int>&vec)
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
/*
    //METHOD-1
    void solve(int i,vector<int>&curr,vector<int>& nums, int tar, vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            if(tar==0)
            {
                ans.push_back(curr);
            }
            return;
        }
        if(nums[i]<=tar)
        {
            curr.push_back(nums[i]);
            //will not pass i+1 as we can have repeatitions..
            solve(i,curr,nums,tar-nums[i],ans);
            curr.pop_back();
        }
        solve(i+1,curr,nums,tar,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) 
    {
        int n= nums.size(); 
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,nums,tar,ans);
        return ans;
    }

    //METHOD-2
    void solve(int i,vector<int>&curr,vector<int>& nums, int tar, vector<vector<int>>&ans)
    {
        if(i>=nums.size() || tar<0)
        {
            return;
        }
        if(tar==0)
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        //will not pass i+1 as we can have repeatitions..
        solve(i,curr,nums,tar-nums[i],ans);
        curr.pop_back();

        solve(i+1,curr,nums,tar,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) 
    {
        int n= nums.size(); 
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,nums,tar,ans);
        return ans;
    }
*/