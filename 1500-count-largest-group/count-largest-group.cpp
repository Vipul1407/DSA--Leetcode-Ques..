class Solution {
public:
    int countLargestGroup(int n) 
    {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            int d=i;
            int sum=0;
            while(d>0)
            {
                sum+= d%10;
                d/=10;
            }
            mp[sum]++;
        }
        int maxi=0;
        int ans=0;
        for(auto i:mp)
        {
            maxi= max(maxi,i.second);
        }
        for(auto i:mp)
        {
            if(i.second==maxi)
            {
                ans++;
            }
        }
        return ans;
    }
};