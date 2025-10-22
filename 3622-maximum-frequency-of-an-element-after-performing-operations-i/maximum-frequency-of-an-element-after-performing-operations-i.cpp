class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) 
    {
        int ans= 1;
        int n= *max_element(begin(nums),end(nums));
        vector<int>freq(n+1,0);
        for(auto i:nums)
        {
            freq[i]++;
        }
        for(int i=1;i<=n;i++)
        {
            freq[i]+= freq[i-1];
        }
        for(int i=0;i<=n;i++)
        {
            int freqcnt= freq[i]- ((i>0)?freq[i-1]:0);
            int l= max(0,i-k);
            int r= min(n,i+k);
            int total= freq[r]- ((l>0)?freq[l-1]:0);
            int newans= freqcnt + min(numOperations, total-freqcnt);
            ans= max(ans,newans);
        }
        return ans;
    }
};