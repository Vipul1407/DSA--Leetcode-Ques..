class Solution {
public:
    //METHOD-3
    //Space Optimized APPROACH..
    int countSquares(vector<vector<int>>& mat) 
    {
        int cnt=0;
        int m= mat.size();
        int n= mat[0].size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                {
                    curr[j]= 1+min({next[j],curr[j+1],next[j+1]});
                }   
                else
                {
                    curr[j]=0;
                }
                cnt+= curr[j];
            }
            next=curr;
        }
        return cnt;
    }
};
/*
    //METHOD-1
    //TDA APPROACH..
    int countSquares(vector<vector<int>>& mat) 
    {
        int cnt=0;
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            dp[0][j]= mat[0][j];
            cnt+= mat[0][j];
        }
        for(int i=0;i<m;i++)
        {
            dp[i][0]= mat[i][0];
            cnt+= mat[i][0];
        }
        cnt-= mat[0][0];

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    dp[i][j]= 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }               
                cnt+= dp[i][j];
            }
        }
        return cnt;
    }
*/