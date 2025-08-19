class Solution {
public:
    //METHOD-2
    //DFS... Cycle detection in directed graph;;
    bool dfs(int i, unordered_map<int,vector<int>>&adj, vector<int>&vis)
    {
        vis[i]=1;
        for(auto &neigh: adj[i])
        {
            if(vis[neigh]==1)
            {
                return false;
            }
            if(vis[neigh]==0)
            {
                if(!dfs(neigh,adj,vis))
                {
                    return false;
                }
            }
        }
        vis[i]=2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>adj;
        vector<int>vis(n,0);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,adj,vis))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
/*
    //METHOD-1
    //BFS using Kahn Algo..
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                cnt++;
            }
        }
        while(q.size())
        {
            auto top=q.front();
            q.pop();
            for(auto neigh: adj[top])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
*/