class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_map<int,int>mp;
        while(true)
        {
            int ans=0;
            while(n>0)
            {
                int digit= n%10;
                ans+= digit*digit;
                n/=10;
            }
            if(ans==1)
            {
                return true;
            }
            else if(mp.find(ans)!=mp.end())
            {
                return false;
            }
            mp[ans]++;
            n=ans;
        }
        return true;
    }
};