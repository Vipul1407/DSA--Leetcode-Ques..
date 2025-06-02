class Solution {
public:
    //METHOD-4
    //OPTIMIZED..
    //TC= O(N)
    long long distributeCandies(int n, int limit) 
    {
        long long ans=0;
        int minc1= max(0,n-2*limit);
        int maxc1= min(n,limit);
        for(int c= minc1; c<=maxc1; c++)
        {
            int N= n-c;
            //N-limit not N-2*limit,,,,
            int minc2= max(0,N-limit);
            int maxc2= min(N,limit);
            ans+= maxc2-minc2+1;
        }
        return ans;
    }
};
/*
    // METHOD-1
    // RECURSIVE..
    // TC= O(LIMIT^3)
    //TLE...
    long long solve(int child, int n, int &limit)
    {
        if (child == 3)
        {
            if (n == 0)
            {
                return 1;
            }
            return 0;
        }
        long long ans = 0;
        for (int i = 0; i <= min(n, limit); i++)
        {
            ans += solve(child + 1, n - i, limit);
        }
        return ans;
    }
    long long distributeCandies(int n, int limit)
    {
        return solve(0, n, limit);
    }

    // METHOD-2
    // TC= O(N^3)
    //TLE...
    long long distributeCandies(int n, int limit)
    {
        long long ans = 0;
        for (int i = 0; i <= min(n, limit); i++)
        {
            for (int j = 0; j <= min(n - i, limit); j++)
            {
                for (int k = 0; k <= min(n - i - j, limit); k++)
                {
                    if (i + j + k == n)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    // METHOD-3
    // TC= O(N^2)
    //TLE....
    long long distributeCandies(int n, int limit)
    {
        long long ans = 0;
        for (int i = 0; i <= min(n, limit); i++)
        {
            for (int j = 0; j <= min(n - i, limit); j++)
            {
                int k = n - i - j;
                if (k >= 0 && k <= limit)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
*/