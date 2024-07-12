class Solution {
public:
    int prime_sum(int n)
    {
        int sumd=0;
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                sumd+=i;
                n/=i;
            }   
        }
        if(n!=1)
        {
            sumd+=n;
        }
        return sumd;
    }
    int smallestValue(int n) 
    {
        while(true)
        {
            int sum= prime_sum(n);
            if(n==sum)
            {
                return n;
            }
            n=sum;
        }
        return n;
    }
};