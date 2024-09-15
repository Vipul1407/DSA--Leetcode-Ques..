class Solution {
public:
    typedef long long ll;
    ll tda(int i,int j,vector<int>& a, vector<int>& b,vector<vector<ll>>&dp)
    {
        //base case signifying to stop
        if(i==4)
        {
            return 0;
        }
        //representing a invalid answer
        if(j>=b.size())
        {
            return -1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //take
        ll take= (ll)((ll)a[i]*(ll)b[j]+ tda(i+1,j+1,a,b,dp));
        //notake
        ll notake= tda(i,j+1,a,b,dp);
        return dp[i][j]= max(take,notake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) 
    {
        vector<vector<ll>>dp(4,vector<ll>(b.size(),-1));
        return tda(0,0,a,b,dp);
    }
};