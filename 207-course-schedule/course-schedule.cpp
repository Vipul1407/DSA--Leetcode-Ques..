class Solution {
public:
    //CYCLE DETECTION IN DIRECTED GRAPH USING DFS..
    bool dfs(int curr, unordered_map<int,vector<int>>&adj, vector<int>&vis, vector<int>&pathvis)
    {
        vis[curr]=1;
        pathvis[curr]=1;
        for(auto neigh: adj[curr])
        {
            //cycle mil gyi.. becoz pathvis bhi h and vis bhi h..
            if(vis[neigh] && pathvis[neigh])
            {
                return true;
            }
            if(!vis[neigh])
            {
                if(dfs(neigh,adj,vis,pathvis))
                {
                    return true;
                }
            }
        }
        //backtracking..
        pathvis[curr]=0;
        return false;
    }
    bool canFinish(int course, vector<vector<int>>& pre) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto i:pre)
        {
            adj[i[1]].push_back(i[0]);
        }
       vector<int>vis(course,0);
       vector<int>pathvis(course,0);
        for(int i=0;i<course;i++)
        {
            if(!vis[i])
            {
                //cycle mil gyi mtlb situation possible ni h...
                if(dfs(i,adj,vis,pathvis))
                {
                    return false;
                }
            }
        }
        //cycle ni mili mtlb situation possible h..
        return true;
    }
};