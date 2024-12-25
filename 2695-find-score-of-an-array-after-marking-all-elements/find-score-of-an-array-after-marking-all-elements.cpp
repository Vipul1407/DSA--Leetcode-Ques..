class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        int n= nums.size();
        long long ans=0;
        vector<int>vis(n,0);//to mark visited index..
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        for(auto i:vec)
        {
            if(vis[i.second]==1)
            {
                continue;
            }
            ans+= i.first;
            vis[i.second]=1;
            if(i.second-1>=0)
            {
                vis[i.second-1]=1;
            }
            if(i.second+1<n)
            {
                vis[i.second+1]=1;
            }
        }
        return ans;
    }
};   