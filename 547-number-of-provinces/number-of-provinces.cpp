class Solution {
public:
    //METHOD-2
    //BFS..
    //TC= O(N^2)
    void bfs(int i,vector<vector<int>>& graph,vector<int>& vis)
    {
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(q.size())
        {
            int newi= q.front();
            q.pop();
            for(int j=0;j<graph.size();j++)
            {
                if(!vis[j] && graph[newi][j]==1)
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
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,graph,vis);
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