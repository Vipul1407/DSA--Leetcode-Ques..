class Solution {
public:
    //METHOD-3
    //BFS..
    void bfs(int i,unordered_map<int,vector<int>>& adj,vector<int>& vis)
    {
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(q.size())
        {
            int newi= q.front();
            q.pop();
            for(auto j:adj[newi])
            {
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) 
    {
        int n= graph.size(); 
        vector<int>vis(n,0);
        int cnt=0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
/*
//METHOD-1
    //DFS..
    //TC= O(N^2)
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
*/