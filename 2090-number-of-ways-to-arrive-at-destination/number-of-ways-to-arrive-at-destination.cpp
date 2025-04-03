class Solution {
public:
    #define ll long long
    const int x= pow(10,9)+7;
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        //min heap storing distance,node..
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        vector<ll>dist(n,LLONG_MAX);
        vector<int>cnt(n,0);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        //assuming 0 is source..
        pq.push({0,0});
        dist[0]=0;
        cnt[0]=1;
        while(pq.size())
        {
            int node= pq.top().second;
            ll prevdis= pq.top().first;
            pq.pop();
            for(auto i:adj[node])
            {
                int no= i.first;
                ll wt= i.second;
                if(prevdis+wt < dist[no])
                {
                    dist[no]= prevdis+wt;
                    pq.push({dist[no],no});
                    cnt[no]= cnt[node];
                }
                else if(prevdis+wt == dist[no])
                {
                    cnt[no]= (cnt[no]+cnt[node])%x;
                }
            }
        }
        return cnt[n-1]%x;
    }
};