class Solution {
public:
    bool isprime(int n)
    {
        if(n<=1)
        {
            return false;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int setbit(int n)
    {
        int cnt=0;
        while(n>0)
        {
            if(n&1)
            {
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) 
    {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int cntset= setbit(i);
            if(isprime(cntset))
            {
                ans++;
            } 
        }
        return ans;
    }
};