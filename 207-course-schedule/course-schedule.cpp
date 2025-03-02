class Solution {
public:
    // METHOD-2
    // CYCLE DETECTION IN DIRECTED GRAPH USING BFS..(KAHN ALGO..)   
    bool canFinish(int course, vector<vector<int>>& pre) 
    {
        queue<int>q;
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(course,0);
        int cnt=0;
        for(auto i:pre)
        {
            // 0->1
            // then 1 should come before 0..
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for(int i=0;i<course;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                cnt++;
            }
        }
        while(q.size())
        {
            auto i= q.front();
            q.pop();
            for(auto &neigh: adj[i])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                    cnt++;
                }
            }
        }
        //means cnt==n we not get cycle , hence return true...
        return cnt==course? true:false;
    }
};
/*
// METHOD-1
// CYCLE DETECTION IN DIRECTED GRAPH USING DFS..
bool dfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &pathvis)
{
    vis[curr] = 1;
    pathvis[curr] = 1;
    for (auto neigh : adj[curr])
    {
        // cycle mil gyi.. becoz pathvis bhi h and vis bhi h..
        if (vis[neigh] && pathvis[neigh])
        {
            return true;
        }
        if (!vis[neigh])
        {
            if (dfs(neigh, adj, vis, pathvis))
            {
                return true;
            }
        }
    }
    // backtracking..
    pathvis[curr] = 0;
    return false;
}
bool canFinish(int course, vector<vector<int>> &pre)
{
    unordered_map<int, vector<int>> adj;
    for (auto i : pre)
    {
        // 0->1
        // then 1 should come before 0..
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(course, 0);
    vector<int> pathvis(course, 0);
    for (int i = 0; i < course; i++)
    {
        if (!vis[i])
        {
            // cycle mil gyi mtlb situation possible ni h...
            if (dfs(i, adj, vis, pathvis))
            {
                return false;
            }
        }
    }
    // cycle ni mili mtlb situation possible h..
    return true;
}
*/