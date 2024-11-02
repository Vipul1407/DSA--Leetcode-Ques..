class Solution {
public:
    int dp[2][101][101];
    int rec(vector<int>& piles,int alice,int i,int M)
    {
        int n=piles.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[alice][i][M]!=-1)
        {
            return dp[alice][i][M];
        }
        int ans= (alice==1)?  -1:INT_MAX;
        int stones=0;
        for(int x=1;x<=min(2*M,n-i);x++)
        {
            stones+= piles[i+x-1];
            //Alice turn..
            if(alice==1)
            {
                //now passing 0 as bob turn next
                ans= max(ans, stones+ rec(piles,0,i+x,max(M,x)));
            }
            //Bob turn..
            else
            {
                //now passing 1 as alice turn next
                ans= min(ans, rec(piles,1,i+x,max(M,x)));
            }
        }
        return dp[alice][i][M]= ans;
    }
    int stoneGameII(vector<int>& piles) 
    {
        int n=piles.size();
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<101;j++)
            {
                for(int k=0;k<101;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        //initially..
        //alice turn
        //i=0
        //M=1
        return rec(piles,1,0,1);
    }
};