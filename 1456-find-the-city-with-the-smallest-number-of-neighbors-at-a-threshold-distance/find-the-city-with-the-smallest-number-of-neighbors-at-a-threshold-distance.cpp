class Solution {
public:
    //METHOD-1..
    //FLOYD WARSHAL'S ALGO..
    int findTheCity(int n, vector<vector<int>>& edges, int threshold)
    {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto i:edges)
        {
            int u= i[0];
            int v= i[1];
            int w= i[2];
            dist[u][v]= w;
            dist[v][u]= w;
        }
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    {
                        dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        /*
            //to detect -ve cycle check if dist[i][j]<0 means there exist a -ve cycle..
        */
        int ans= n+1;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j]<=threshold)
                {
                    cnt++;
                }
            }
            if(cnt<=ans)
            {
                city= i;
                ans= cnt;
            }
        }
        return city;
    }
};
/*
    //METHOD-2
    //USING DIKSHTRA..
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
*/