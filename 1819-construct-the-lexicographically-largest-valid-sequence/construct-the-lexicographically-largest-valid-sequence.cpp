class Solution {
public:
    bool solve(int i,int n,vector<int>&ans,vector<int>used)
    {
        if(i>=ans.size())
        {
            return true;
        }
        if(ans[i]!=0)
        {
            return solve(i+1,n,ans,used);
        }
        for(int num=n;num>=1;num--)
        {
            if(used[num]==1)
            {
                continue;
            }

            //try..
            ans[i]= num;
            used[num]= 1;

            //explore..
            if(num==1)
            {
                if(solve(i+1,n,ans,used))
                {
                    return true;
                }
            }
            else
            {
                int j= i+num;
                if(j<ans.size() && ans[j]==0)
                {
                    ans[j]= num;
                    if(solve(i+1,n,ans,used))
                    {
                        return true;
                    }
                    ans[j]= 0; 
                }           
            }
            
            //backtracking..
            ans[i]= 0;
            used[num]= 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int>ans(2*n-1,0);
        vector<int>used(n+1,0);
        solve(0,n,ans,used);
        return ans;
    }
};