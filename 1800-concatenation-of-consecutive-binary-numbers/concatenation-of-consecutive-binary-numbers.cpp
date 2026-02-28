class Solution {
public:
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
};