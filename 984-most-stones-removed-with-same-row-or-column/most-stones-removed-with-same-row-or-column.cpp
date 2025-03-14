class Solution {
public:  
    //METHOD-2
    //USING BFS..
    void bfs(int i,vector<vector<int>> &stones, vector<int> &vis)
    {
        int n= stones.size();
        vis[i]=1;
        queue<int>q;
        q.push(i);
        while(q.size())
        {
            int x= stones[q.front()][0];
            int y= stones[q.front()][1];
            q.pop();
            for(int j=0;j<n;j++)
            {
                if(!vis[j] && (stones[j][0]==x || stones[j][1]==y))
                {
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n= stones.size();
        vector<int>vis(n,0);
        int grp=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                grp++;
                bfs(i,stones,vis);
            }
        }
        return n-grp;
    }
};
/*
// METHOD-1
// DFS...
void dfs(int i, vector<vector<int>> &stones, vector<int> &vis)
{
    int n = stones.size();
    vis[i] = 1;
    int x = stones[i][0];
    int y = stones[i][1];
    for (int j = 0; j < n; j++)
    {
        // present in same row or same col then mark it as visted..
        if (!vis[j] && (stones[j][0] == x || stones[j][1] == y))
        {
            dfs(j, stones, vis);
        }
    }
}
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<int> vis(n, 0);
    int grp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            grp++;
            dfs(i, stones, vis);
        }
    }
    return n - grp;
}

*/