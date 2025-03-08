class Solution {
public:
    // METHOD-2
    // OPTIMIZED..
    // SLIDING WINDOW..
    int minimumRecolors(string blocks, int k) 
    {
        int n= blocks.size();
        int ans=n;
        int i=0,j=0;
        int white=0;
        while(j<n)
        {
            if(blocks[j]=='W')
            {
                white++;
            }
            if(j-i+1==k)
            {
                ans= min(ans,white);
                if(blocks[i]=='W')
                {
                    white--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE
// BEATS 100%
int minimumRecolors(string blocks, int k)
{
    int n = blocks.size();
    int ans = n;
    for (int i = 0; i <= n - k; i++)
    {
        int white = 0;
        for (int j = i; j < i + k; j++)
        {
            if (blocks[j] == 'W')
            {
                white++;
            }
        }
        ans = min(ans, white);
    }
    return ans;
}
*/