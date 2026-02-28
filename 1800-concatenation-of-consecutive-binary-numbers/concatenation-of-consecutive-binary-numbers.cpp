class Solution {
public:
    //METHOD-2..
    const int MOD= 1000000007;
    int concatenatedBinary(int n) 
    {
        long long ans=0;
        int shift=0;
        for(int i=1;i<=n;i++)
        {
            if((i&(i-1))==0)
            {
                shift++;
            } 
            ans= ((ans<<shift)%MOD +i)%MOD;
        }  
        return (int)(ans%MOD);  
    }
};
/*
    //METHOD-1..
    const int MOD= 1000000007;
    int concatenatedBinary(int n) 
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int shift= log2(i)+1; 
            ans= ((ans<<shift)%MOD +i)%MOD;
        }  
        return (int)(ans%MOD);  
    }
*/