#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        //src=0
        //dest=n-1
        int x=pow(10,9)+7;
        unordered_map<ll,vector<pair<ll,ll>>>adj;//node1,node2,wt
        //0-->1 with wt.3
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>time(n,LONG_MAX);
        vector<ll>ways(n,0);
        time[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            ll node=pq.top().second;
            ll prevdis=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                ll no=it.first;
                ll wt=it.second;
                if (prevdis + wt < time[no])
                {
                    time[no] = prevdis + wt;
                    pq.push({time[no], no});
                    ways[no] = ways[node]; // Update ways array
                }
                else if (prevdis + wt == time[no])
                {
                    ways[no] = (ways[no] + ways[node]) % x;
                }
            }
        }
        return ways[n-1]%x;//n-1 is dest 
    }
};