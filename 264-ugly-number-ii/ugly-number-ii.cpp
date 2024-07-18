class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>dp(n,0);
        dp[0]=1;
        int p2=0;
        int p3=0;
        int p5=0;
        for(int i=1;i<n;i++)
        {
            int a= dp[p2]*2;
            int b= dp[p3]*3;
            int c= dp[p5]*5;
            dp[i]= min(a,min(b,c));
            if(dp[i]==a)
            {
                p2++;
            }
            if(dp[i]==b)
            {
                p3++;
            }
            if(dp[i]==c)
            {
                p5++;
            }
        }
        return dp[n-1];
    }
};