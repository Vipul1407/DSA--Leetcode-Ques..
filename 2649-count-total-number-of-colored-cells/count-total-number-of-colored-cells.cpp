class Solution {
public:
    
    // METHOD-2
    // Aryan Mittal..
    long long coloredCells(int n) 
    {
        long long ans=1;
        long long val=4;
        if(n==1)
        {
            return 1;
        }
        for(int i=2;i<=n;i++)
        {
            ans+= val; 
            val= 4*i;
        }
        return ans;
    }
};
/*
// METHOD-1
long long coloredCells(int n)
{
    return 1 + 4LL * n * (n - 1) / 2;
}
*/