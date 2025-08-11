class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int>power;
        vector<int>ans;
        const int mod= 1000000007;
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))
            {
                power.push_back(1<<i);
            }
        }
    
        for(auto i:queries)
        {
            long long p=1;  
            int l= i[0];
            int r= i[1];
            for(int i=l;i<=r;i++)
            {
                p= (p*power[i])%mod;
            }
            ans.push_back((int)p);
        }
        return ans;
    }
};