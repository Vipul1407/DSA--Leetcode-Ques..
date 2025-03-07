class Solution {
public:
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
*/