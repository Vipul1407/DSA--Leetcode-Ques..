class Solution {
public:
    bool isconnected(int u, int v, unordered_map<int,vector<int>>&adj, vector<int>&vis)
    {
        vis[u]=1;
        if(u==v)
        {
            return true;
        }
        for(auto &i:adj[u])
        {
            if(!vis[i] && isconnected(i,v,adj,vis))
            {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n= edges.size();
        unordered_map<int,vector<int>>adj;
        vector<int>ans;
        for(auto i:edges)
        {
            int u= i[0];
            int v= i[1];
            vector<int>vis(n+1,0);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && isconnected(u,v,adj,vis))
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