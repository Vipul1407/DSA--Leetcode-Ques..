class Solution {
public:
    // METHOD-4
    // USING DFS FORMING ADJ LIST...
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
    int findCircleNum(vector<vector<int>>& graph) 
    {
        int n= graph.size();
        unordered_map<int,vector<int>>adj;
        vector<int>vis(n,0);
        int cnt=0;
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
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
/*
// METHOD-1
// DFS.. WITHOUT USING ADJ LIST...
// TC= O(N^2)
void dfs(int i, vector<vector<int>> &graph, vector<int> &vis)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = 1;
    for (int j = 0; j < graph.size(); j++)
    {
        if (graph[i][j] == 1)
        {
            dfs(j, graph, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, graph, vis);
        }
    }
    return cnt;
}

// METHOD-2
//  BFS..  WITHOUT USING ADJ LIST...
//  TC= O(N^2)
void bfs(int i, vector<vector<int>> &graph, vector<int> &vis)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (q.size())
    {
        int newi = q.front();
        q.pop();
        for (int j = 0; j < graph.size(); j++)
        {
            if (!vis[j] && graph[newi][j] == 1)
            {
                q.push(j);
                vis[j] = 1;
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            bfs(i, graph, vis);
        }
    }
    return cnt;
}

// METHOD-3
// USING BFS FORMING ADJ LIST...
void bfs(int i, unordered_map<int, vector<int>> &adj, vector<int> &vis)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (q.size())
    {
        int newi = q.front();
        q.pop();
        for (auto j : adj[newi])
        {
            if (!vis[j])
            {
                q.push(j);
                vis[j] = 1;
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    int cnt = 0;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i, adj, vis);
            cnt++;
        }
    }
    return cnt;
}
*/