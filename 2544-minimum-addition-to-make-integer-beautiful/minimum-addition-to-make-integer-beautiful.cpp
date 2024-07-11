class Solution {
public:
    long long makeIntegerBeautiful(long long n, int k) 
    {
        long long num=n;//used for calculating sum of digits
        long long sum= 0;//sum of digits
        long long ans=0;//final ans
        while(num>0)
        {
            sum+= num%10;
            num/=10;
        }
        if(sum<=k)
        {
            return 0;
        }
        //now process to make digits to 0
        long long mod=10;
        while(sum>k)
        {
            while(n%mod==0)
            {
                mod*=10;
            }
            ans+= mod-(n%mod);
            n+= mod- (n%mod);
            long long num=n;
            sum=0;
            while(num>0)
            {
                sum+= num%10;
                num/=10;
            }
        }
        return ans;
    }
};