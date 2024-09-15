class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& a, vector<int>& b) 
    {
        int n= b.size(); 
        vector<vector<ll>>dp(5,vector<ll>(n+1,-1e9));
        for(int j=0;j<=n;j++)
        {
            dp[4][j]= 0;
        }
        for(int i=3;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                ll take= (ll)((ll)a[i]*(ll)b[j]+ dp[i+1][j+1]);
                ll notake= dp[i][j+1];
                dp[i][j]= max(take,notake);
            }
        }
        return dp[0][0];
    }
};