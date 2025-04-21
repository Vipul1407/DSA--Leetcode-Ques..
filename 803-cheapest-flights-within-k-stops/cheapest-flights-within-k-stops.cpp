class Solution {
public:
    //METHOD-2
    //UISNG SIMPLE QUEUE...
    typedef pair<int,pair<int,int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        //src, dest, wt...
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:flights)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dis(n,1e9);
        //min heap.. stops,src,wt.
        queue<P>pq;
        pq.push({0,{src,0}});
        dis[src]=0;
        while(pq.size())
        {
            auto top= pq.front();
            int stops= top.first;
            int node= top.second.first;
            int d= top.second.second;
            pq.pop();
            if(stops>k)
            {
                continue;
            }
            for(auto i:adj[node])
            {
                int neigh= i.first;
                int w= i.second;
                if(d+w< dis[neigh])
                {
                    dis[neigh]= d+w;
                    pq.push({stops+1,{neigh,dis[neigh]}});
                }
            }
        }
        return dis[dst]==1e9? -1:dis[dst];
    }
};
/*
    //METHOD-1
    //USING PRIORITY QUEUE...

    typedef pair<int,pair<int,int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        //src, dest, wt...
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:flights)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dis(n,1e9);
        //min heap.. stops,src,wt.
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{src,0}});
        dis[src]=0;
        while(pq.size())
        {
            auto top= pq.top();
            int stops= top.first;
            int node= top.second.first;
            int d= top.second.second;
            pq.pop();
            if(stops>k)
            {
                continue;
            }
            for(auto i:adj[node])
            {
                int neigh= i.first;
                int w= i.second;
                if(d+w< dis[neigh])
                {
                    dis[neigh]= d+w;
                    pq.push({stops+1,{neigh,dis[neigh]}});
                }
            }
        }
        return dis[dst]==1e9? -1:dis[dst];
    }
*/