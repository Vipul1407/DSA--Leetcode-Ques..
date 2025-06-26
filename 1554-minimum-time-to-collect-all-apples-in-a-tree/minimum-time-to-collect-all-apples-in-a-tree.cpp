class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&adj, int start, int par, vector<bool>& hasApple)
    {
        int cnt=0;
        for(auto i:adj[start])
        {
            if(i==par)
            {
                continue;
            }
            int time= dfs(adj,i,start,hasApple);
            if(time>0 || hasApple[i])
            {
                cnt+= time+2;
            }
        }
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }    
        //starting form node 0 assuming its parent to be -1
        return dfs(adj,0,-1,hasApple);
    }
};