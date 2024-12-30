class Solution {
public:
    #define MOD 1000000007
    int countGoodStrings(int l, int r, int zero, int one) 
    {
        if(zero>r && one>r)
        {
            return 0;
        }
        vector<int>dp(r+1,0);
        for(int size=r;size>=0;size--)
        {
            int cnt= (size>=l && size<=r)? 1:0;
            int ztake= (size+zero<=r)? dp[size+zero]:0;
            int otake= (size+one<=r)? dp[size+one]:0;
            dp[size]= (cnt+otake+ztake)%MOD;
        }
        return dp[0];
    }
};
/*
// METHOD-1
// RECURSIVE APPROACH..
#define MOD 1000000007
int rec(int &l, int &r, int &zero, int &one, int size)
{
    if (size > r)
    {
        return 0;
    }
    int cnt = 0;
    // can do only if(size>=l){cnt=1;} as we have already checked above that if size=r then return 1
    if (size >= l && size <= r)
    {
        cnt = 1;
    }
    int ztake = rec(l, r, zero, one, size + zero) % MOD;
    int otake = rec(l, r, zero, one, size + one) % MOD;
    return (ztake + otake + cnt) % MOD;
}
int countGoodStrings(int l, int r, int zero, int one)
{
    return rec(l, r, zero, one, 0) % MOD;
}

// METHOD-2
// TDA..
#define MOD 1000000007
int rec(int &l, int &r, int &zero, int &one, int size, vector<int> &dp)
{
    if (size > r)
    {
        return 0;
    }
    if (dp[size] != -1)
    {
        return dp[size];
    }
    int cnt = 0;
    // can do this as we have already checked abve that if size.=r then return 1;
    // if(size>=l){return 1;}
    if (size >= l && size <= r)
    {
        cnt = 1;
    }
    int ztake = rec(l, r, zero, one, size + zero, dp) % MOD;
    int otake = rec(l, r, zero, one, size + one, dp) % MOD;
    return dp[size] = (ztake + otake + cnt) % MOD;
}
int countGoodStrings(int l, int r, int zero, int one)
{
    vector<int> dp(r + 1, -1);
    return rec(l, r, zero, one, 0, dp) % MOD;
}
*/