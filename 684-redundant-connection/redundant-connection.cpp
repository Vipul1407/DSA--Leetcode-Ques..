class Solution {
public:
    // METHOD-3
    // DSU....
    int findupar(int node, vector<int> &parent)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node], parent);
    }
    void unionbysize(int u, int v, vector<int> &rank, vector<int> &parent)
    {
        int up_u = findupar(u, parent);
        int up_v = findupar(v, parent);
        if (up_u == up_v)
        {
            return;
        }
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if(rank[up_u]>rank[up_v])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v]= up_u;
            rank[up_u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n= edges.size();

        vector<int>rank(n+1,0);
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            if(findupar(u,parent) == findupar(v,parent))
            {
                return {u,v};
            }
            unionbysize(u,v,rank,parent);
        }
        return {-1,-1};
    }
};
/*
// METHOD-1
// DFS..
bool isconnected(int u, int v, unordered_map<int, vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    if (u == v)
    {
        return true;
    }
    for (auto &i : adj[u])
    {
        if (!vis[i] && isconnected(i, v, adj, vis))
        {
            return true;
        }
    }
    return false;
}
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        vector<int> vis(n, 0);
        if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && isconnected(u, v, adj, vis))
        {
            ans.push_back(u);
            ans.push_back(v);
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return ans;
}

//METHOD-2
    //BFS..
    bool isconnect(int u,int v,unordered_map<int,vector<int>>&adj)
    {
        unordered_set<int>vis;
        vis.insert(u);
        queue<int>q;
        q.push(u);
        while(q.size())
        {
            auto top= q.front();
            q.pop();
            if(top==v)
            {
                return true;
            }
            for(auto &i:adj[top])
            {
                if(vis.find(i)==vis.end())
                {
                    q.push(i);
                    vis.insert(i);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n= edges.size();
        vector<int>ans;
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            int u= i[0];
            int v= i[1];
            if(adj.find(u)!=adj.end() &&  adj.find(v)!=adj.end() && isconnect(u,v,adj))
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return ans;
    }
*/