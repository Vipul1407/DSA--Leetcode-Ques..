class Solution 
{
public:

    bool isprime(int num)
    {
        int cnt = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                cnt++;
                if (num / i != i)
                {
                    cnt++;
                }
                if (cnt > 2)
                {
                    return false;
                }
            }
        }
        // becoz 1 is not a prime number
        return cnt == 2;
    }
    vector<int> closestPrimes(int left, int right) 
    {
        int prev=-1;
        int diff= INT_MAX;
        int l=-1;
        int r=-1;
        for(int i=left;i<=right;i++)
        {
            if(isprime(i))
            {
                if(prev==-1)
                {
                    prev=i;
                }
                else
                {
                    if(abs(i-prev)<diff)
                    {
                        l=prev;
                        r=i;
                        diff= abs(i-prev);
                    }
                    prev=i;
                }
            }
        }
        return {l,r};
    }
};