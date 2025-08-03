class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int p, int k) 
    {
        int n= fruits.back()[0];
        int ans=0;
        //prefix sum of quantities of fruits...
        vector<int>prefixsum(n+1,0);

        //store positions in f..
        vector<int>f(n+1,0);
        for(auto i:fruits)
        {
            f[i[0]]= i[1];
        }

        prefixsum[0]= f[0];
        for(int i=1;i<=n;i++)
        {
            prefixsum[i]= prefixsum[i-1]+f[i];
        }

        for(int d=0;d<=k/2;d++)
        {
            //case1: go d left then k-2d right....
            int i= max(0,p-d);
            int remain= k-2*d;
            int j= min(n,p+remain);
            
            if(i<=j)
            {
                int q= i>0? prefixsum[j]-prefixsum[i-1]: prefixsum[j];
                ans= max(ans,q);
            }

            //case2: go d right then k-2d left....
            i= max(0,p-remain);
            j= min(n,p+d);
            //remain will be same for case2...
            //int remain= k-2*d;
        
            if(i<=j)
            {
                int q= i>0? prefixsum[j]-prefixsum[i-1]: prefixsum[j];
                ans= max(ans,q);
            }
        }
        return ans;
    }
};