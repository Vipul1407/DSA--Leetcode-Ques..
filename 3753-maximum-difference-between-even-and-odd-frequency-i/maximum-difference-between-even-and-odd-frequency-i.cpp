class Solution {
public:
    int maxDifference(string s) 
    {
        int n= s.size();
        unordered_map<int,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        int maxi_odd=0;
        int mini_even=n;
        for(auto i:mp)
        {
            //even
            if(i.second%2==0)
            {
                mini_even= min(mini_even,i.second);
            }
            else
            {
                maxi_odd= max(maxi_odd,i.second);
            }
        }
        return maxi_odd-mini_even;
    }
};