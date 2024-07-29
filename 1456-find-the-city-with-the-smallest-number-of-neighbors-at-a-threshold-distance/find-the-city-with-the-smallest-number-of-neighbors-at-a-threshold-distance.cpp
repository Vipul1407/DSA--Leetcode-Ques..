class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int td) 
    {
        vector<pair<int,int>>adj[n];
        for(auto i:edges)
        {
            int u= i[0];
            int v= i[1];
            int w= i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //MIN HEAP..
        int city=0;
        int mincnt= n+1;
        for(int i=0;i<n;i++)
        {
            vector<int>dis(n,INT_MAX);
            dis[i]=0;
            //distance, node
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,i});
            while(!pq.empty())
            {
                int d= pq.top().first;
                int node= pq.top().second;
                pq.pop();
                for(auto it:adj[node])
                {
                    int neigh= it.first;
                    int wt= it.second;
                    if(d+wt< dis[neigh])
                    {
                        dis[neigh]= d+wt;
                        pq.push({dis[neigh],neigh});
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dis[j]<=td)
                {
                    cnt++;
                }
            }
            if(cnt<=mincnt)
            {
                mincnt= cnt;
                city= i;
            }
        }
        return city;
    }
};