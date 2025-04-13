class Solution {
public:
    const int MOD= 1000000007;
    long long power(long long a, long long b)
    {
        if(b==0)
        {
            return 1;
        }
        long long half= power(a,b/2);
        long long res= (half*half)%MOD;
        if(b%2==1)
        {
           res= (res*a)%MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) 
    {
        //number of even index is: (n+1)/2
        //number of odd index is:  n/2
        //even idx can contain 5 even no. like 0,2,4,6,8
        //odd idx can contain 4 prime no. like 2,3,5,7
        //res string can contain leading zeros also..
        return (long long)power(5,(n+1)/2)*power(4,(n/2)) %MOD;
    }
};