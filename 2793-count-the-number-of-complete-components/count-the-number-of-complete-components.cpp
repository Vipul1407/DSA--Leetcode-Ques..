
//CONNECTED COMPONENT IS THAT WHICH CONTAINS EDGE B/W EVERY CONNECTED NODE IN GRAPH..
//Means Total edges in graph is n(n-1)/2 
//METHOD-3
//DSU..(DISJOINT SET)
//TC= O(E* Alpha(V))
class DSU
{
    public:
    vector<int>parent,size;
    DSU(int n)
    {
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        size.resize(n+1,1);
    }
    int findupar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]= findupar(parent[node]);
    }
    void unionbysize(int u,int v)
    {
        int up_u= findupar(u);
        int up_v= findupar(v);
        if(up_u==up_v)
        {
            return;
        }
        else if(parent[up_u]<parent[up_v])
        {
            parent[up_u]= up_v;
            size[up_v]+= size[up_u];
        }
        else
        {
            parent[up_v]= up_u;
            size[up_u]+= size[up_v];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        DSU ds(n);
        //storing count of edges in mp..
        unordered_map<int,int>mp;
        for(auto &i:edges)
        {
            int u= i[0];
            int v= i[1];
            ds.unionbysize(u,v);
        }
        for(auto &i:edges)
        {
            int root= ds.findupar(i[0]);
            mp[root]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                //nodes will be the size..
                int v= ds.size[i];
                //edges will be stored in mp..
                int e= mp[i];;
                if(e== v*(v-1)/2)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
/*
//CONNECTED COMPONENT IS THAT WHICH CONTAINS EDGE B/W EVERY CONNECTED NODE IN GRAPH..
//Means Total edges in graph is n(n-1)/2 
    //METHOD-1
    //DFS..
    void dfs(int i,unordered_map<int,vector<int>>&adj, vector<int>&vis, int &v, int &e)
    {
        vis[i]=1;
        v++;
        e+= adj[i].size();
        for(auto j:adj[i])
        {
            if(!vis[j])
            {
                dfs(j,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int v=0;
                int e=0;
                dfs(i,adj,vis,v,e);
                if(e== v*(v-1))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    //CONNECTED COMPONENT IS THAT WHICH CONTAINS EDGE B/W EVERY CONNECTED NODE IN GRAPH..
    //Means Total edges in graph is n(n-1)/2 
    //METHOD-2
    //BFS..
    void bfs(int i,unordered_map<int,vector<int>>&adj,vector<int>&vis,int &v,int &e)
    {
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(q.size())
        {
            int top= q.front();
            q.pop();
            v++;
            e+= adj[top].size();
            for(auto j:adj[top])
            {
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int v=0;
                int e=0;
                bfs(i,adj,vis,v,e);
                if(e== v*(v-1))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
*/