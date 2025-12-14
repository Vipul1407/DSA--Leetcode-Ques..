class Solution {
public:
    #define MOD 1000000007
    int numberOfWays(string corridor) 
    {
        int n= corridor.size();
        long long ans=1;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')
            {
                vec.push_back(i);
            }
        }
        if(vec.size()%2!=0 || vec.size()==0)
        {
            return 0;
        }        
        for(int i=2;i<vec.size();i+=2)
        {
            ans= (ans*(vec[i]-vec[i-1])%MOD)%MOD;
        }
        return ans%MOD;
    }
};