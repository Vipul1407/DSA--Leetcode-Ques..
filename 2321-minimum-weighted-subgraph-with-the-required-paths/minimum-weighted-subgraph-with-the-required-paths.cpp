class Solution {
public:
    typedef long long ll;
    void dijsktra(int src, unordered_map<int,vector<pair<int,int>>>&adj, vector<ll>&dist)
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            ll d= pq.top().first;
            ll node= pq.top().second;
            pq.pop();
            if(d>dist[node])
            {
                continue;
            }
            for(auto &i: adj[node])
            {
                int neigh= i.first;
                int w= i.second;
                ll total= w+d;
                if(d+w< dist[neigh])
                {
                    dist[neigh]= total;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        unordered_map<int,vector<pair<int,int>>>adj;
        unordered_map<int,vector<pair<int,int>>>revadj;
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            revadj[i[1]].push_back({i[0],i[2]});
        }
        vector<ll>ds1(n,LLONG_MAX);
        vector<ll>ds2(n,LLONG_MAX);
        vector<ll>dd(n,LLONG_MAX);
        dijsktra(src1,adj,ds1);
        dijsktra(src2,adj,ds2);
        dijsktra(dest,revadj,dd);

        ll ans= LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(ds1[i]==LLONG_MAX || ds2[i]==LLONG_MAX || dd[i]==LLONG_MAX)
            {
                continue;
            }
            ans= min(ans, ds1[i]+ds2[i]+dd[i]);
        }
        return ans==LLONG_MAX? -1:ans;
    }
};