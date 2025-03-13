class Solution {
public:
    //METHOD-2
    //DFS..
    //Same as No. of Island
    void dfs(int i, unordered_map<int,vector<int>>&adj, vector<int>&vis)
    {
        vis[i]=1;
        for(auto &j:adj[i])
        {
            if(!vis[j])
            {
                dfs(j,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) 
    {
        int edges= conn.size();
        if(edges<n-1)
        {
            return -1;
        }
        int cnt=0;
        unordered_map<int,vector<int>>adj;
        for(auto i:conn)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt-1;
    }
};
/*
// METHOD-1
// DSU...

class DSU
{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findupar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]= findupar(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int up_u=  findupar(u);
        int up_v=  findupar(v);
        if(up_u==up_v)
        {
            return;
        }
        if(rank[up_u]<rank[up_v])
        {
            parent[up_u]= up_v;
        }
        else if(rank[up_u]>rank[up_v])
        {
            parent[up_v]= up_u;
        }
        else
        {
            parent[up_v]= up_u;
            rank[up_u]++;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) 
    {
        int edges= conn.size();
        if(edges<n-1)
        {
            return -1;
        }
        DSU ds(n);
        for(auto i:conn)
        {
            int u= i[0];
            int v= i[1];
            if(ds.findupar(u)!=ds.findupar(v))
            {
                ds.unionbyrank(u,v);
            }
        }
        int need =0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                need++;
            }
        }
        return need-1;
    }
};
*/