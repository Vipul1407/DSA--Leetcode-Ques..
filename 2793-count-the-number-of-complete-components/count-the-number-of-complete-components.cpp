class Solution {
public:
    //CONNECTED COMPONENT IS THAT WHICH CONTAINS EDGE B/W EVERY CONNECTED NODE IN GRAPH..
    //METHOD-1
    //DFS..
    void dfs(int i,unordered_map<int,vector<int>>&adj, vector<int>&vis, int &v, int &e)
    {
        vis[i]=1;
        v++;
        e+= adj[i].size();
        for(auto j:adj[i])
        {
            if(!vis[j])
            {
                dfs(j,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int v=0;
                int e=0;
                dfs(i,adj,vis,v,e);
                if(e== v*(v-1))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};