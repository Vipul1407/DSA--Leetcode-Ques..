class Solution {
public:
    void dfs(int i,vector<vector<int>>& stones, vector<int>&vis)
    {
        int n= stones.size();
        vis[i]=1;
        int x= stones[i][0];
        int y= stones[i][1];
        for(int j=0;j<n;j++)
        {
            if(!vis[j] && (stones[j][0]==x || stones[j][1]==y))
            {
                dfs(j,stones,vis);
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
                dfs(i,stones,vis);
            }
        }
        return n-grp;
    }
};