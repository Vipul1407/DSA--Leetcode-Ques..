class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int>& vis)
    {
        if(vis[i])
        {
            return;
        }
        vis[i]=1;
        for(int j=0;j<graph.size();j++)
        {
            if(graph[i][j]==1)
            {
                dfs(j,graph,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) 
    {
        int n= graph.size();
        
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,graph,vis);
            }
        }    
        return cnt;
    }
};