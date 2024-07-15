class Solution {
public:
    //TC= O(N)+O(N* LOG(LOGN))= O(N)
    //SC= O(N)
    int countPrimes(int n) 
    {
        int cnt=0;
        vector<int>arr(n+1,1);
        //0 and 1 is not prime
        //arr[0]=0;
        //arr[1]=0;

        //go upto sqrt(n)
        for(auto i=2;i*i<=n;i++)
        {
            if(arr[i]==1)
            {
                //starting from i*i
                for(int j=i*i;j<=n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }

        for(int i=2;i<n;i++)
        {
            if(arr[i]==1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};