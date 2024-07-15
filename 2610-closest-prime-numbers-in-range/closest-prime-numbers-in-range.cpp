class Solution {
public:

    vector<int> closestPrimes(int left, int right) 
    {
        //SIEVE OF ERATOSTHENES
        vector<int>prime(right+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=right;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i;j<=right;j+=i)
                {
                    prime[j]=0;
                }
            }
        }

        //NOW GETTING FINAL ANS
        int prev=-1;
        int diff= INT_MAX;
        int l=-1;
        int r=-1;
        for(int i=left;i<=right;i++)
        {
            if(prime[i]==1)
            {
                if(prev==-1)
                {
                    prev=i;
                }
                else
                {
                    if(abs(i-prev)<diff)
                    {
                        diff= abs(i-prev);
                        l=prev;
                        r=i;
                    }
                    prev=i;
                }
            }
        }
        return {l,r};
    }
};  