class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int n= blocks.size();
        int ans=n;
        for(int i=0;i<=n-k;i++)
        {   
            int white=0;
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j]=='W')
                {
                    white++;
                }
            }
            ans= min(ans,white);
        }
        return ans;
    }
};