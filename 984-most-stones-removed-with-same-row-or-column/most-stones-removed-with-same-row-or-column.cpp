class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findupar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int up_u = findupar(u);
        int up_v = findupar(v);
        if (up_u == up_v)
        {
            return;
        }
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution
{
public:
//METHOD-3
//UISNG DISJOINTSET(DSU..)
    int removeStones(vector<vector<int>>& stones) 
    {
        int n= stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto i:stones)
        {
            maxrow= max(maxrow,i[0]);
            maxcol= max(maxcol,i[1]);
        }
        DSU ds(maxrow+maxcol+2);
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            int u= stones[i][0];
            int v= stones[i][1]+maxrow+1;
            ds.unionbyrank(u,v);
            st.insert(u);
            st.insert(v);
        }
        int grp=0;
        for(auto i:st)
        {
            if(ds.parent[i]==i)
            {
                grp++;
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
*/