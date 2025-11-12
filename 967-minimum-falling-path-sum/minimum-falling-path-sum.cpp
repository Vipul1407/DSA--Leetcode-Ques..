class Solution {
public:
    //METHOD-3
    //BUA..
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1)
                {
                    dp[i][j]= mat[i][j];
                }
                int ans= INT_MAX;
                for(int shift=-1;shift<=1;shift++)
                {
                    int newj= j+shift;
                    if(newj>=0 && newj<n)
                    {
                        ans= min(ans,dp[i+1][newj]);
                    }
                }
                dp[i][j]= mat[i][j]+ans;
            }
        }
        //returning the max ans from last row of dp table..
        int ans= INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans= min(ans,dp[0][j]);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,vector<vector<int>>& mat)
    {
        int m= mat.size();
        int n= mat[0].size();
        //last row reached..
        if(i==m-1)
        {
            return mat[i][j];
        }
        int ans= INT_MAX;
        for(int shift=-1;shift<=1;shift++)
        {
            int newj= j+shift;
            if(newj>=0 && newj<n)
            {
                ans= min(ans,rec(i+1,newj,mat));
            }
        }
        return mat[i][j]+ ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        int ans= INT_MAX;
        //starting from 1st row..
        for(int j=0;j<n;j++)
        {
            ans= min(ans,rec(0,j,mat));
        }
        return ans;
    }

    //METHOD-2
    //TDA..
    int rec(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&dp)
    {
        int m= mat.size();
        int n= mat[0].size();
        if(i==m-1)
        {
            return mat[i][j];
        }
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }
        int ans= INT_MAX;
        for(int shift=-1;shift<=1;shift++)
        {
            int newj= j+shift;
            if(newj>=0 && newj<n)
            {
                ans= min(ans,rec(i+1,newj,mat,dp));
            }
        }
        return dp[i][j]= mat[i][j]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        //DO not initialize with -1 since mat can take negative values also => fill dp with INT_MAX
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        int ans= INT_MAX;
        //starting from 1st row..
        for(int j=0;j<n;j++)
        {
            ans= min(ans,rec(0,j,mat,dp));
        }
        return ans;
    }
*/