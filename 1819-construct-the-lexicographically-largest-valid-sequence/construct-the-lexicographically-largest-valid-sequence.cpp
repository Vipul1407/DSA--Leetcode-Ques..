class Solution {
public:
    bool solve(int i, int n, vector<int>&used, vector<int>&ans)
    {
        if(i>=ans.size())
        {
            return true;
        }
        if(ans[i]!=-1)
        {
            return solve(i+1,n,used,ans);
        }
        for(int num=n;num>=1;num--)
        {
            if(used[num]==1)
            {
                continue;
            }
            used[num]=1;
            ans[i]=num;
            if(num==1)
            {
                if(solve(i+1,n,used,ans))
                {
                    return true;
                }
            }
            else
            {
                int j= ans[i]+i;
                if(j<ans.size() && ans[j]==-1)
                {
                    ans[j]= num;
                    if(solve(i+1,n,used,ans))
                    {
                        return true;
                    }
                    ans[j]=-1;
                }
            }
            used[num]=-1;
            ans[i]=-1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int>ans(2*n-1,-1);
        vector<int>used(n+1,-1);
        solve(0,n,used,ans);
        return ans;
    }
};