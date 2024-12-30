class Solution {
public:
    #define MOD 1000000007
    int rec(int &l,int &r,int &zero,int &one, int size, vector<int>&dp)
    {
        if(size>r)
        {
            return 0;
        }
        if(dp[size]!=-1)
        {
            return dp[size];
        }
        int cnt=0;
        if(size>=l && size<=r)
        {
            cnt=1;
        }
        int ztake= rec(l,r,zero,one,size+zero,dp)%MOD;
        int otake=  rec(l,r,zero,one,size+one,dp)%MOD;
        return dp[size]= (ztake+otake+cnt)%MOD;

    }
    int countGoodStrings(int l, int r, int zero, int one) 
    {
        vector<int>dp(r+1,-1);
        return rec(l,r,zero,one,0,dp)%MOD;
    }
};