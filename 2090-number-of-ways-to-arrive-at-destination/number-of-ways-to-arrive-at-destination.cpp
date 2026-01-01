class Solution {
public:
    typedef pair<long long,int>p;
    const int mod= 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>cnt(n,0);
        vector<long long>dist(n,LLONG_MAX);

        for(auto i:roads)
        {
            //src dest cost
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        dist[0]=0;
        cnt[0]=1;
        while(pq.size())
        {
            long long cost= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                long long d= i.second;
                int neigh= i.first;
                if(d+cost< dist[neigh])
                {
                    dist[neigh]= d+cost;
                    pq.push({d+cost,neigh});
                    cnt[neigh]=cnt[node];
                }
                else if(d+cost==dist[neigh])
                {
                    cnt[neigh]= (cnt[neigh]+cnt[node])%mod;
                }
            }
        }
        return cnt[n-1]%mod;
    }
};





















