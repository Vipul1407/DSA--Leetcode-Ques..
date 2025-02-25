class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>bobmap;
    int aliceincome= INT_MIN;

    bool dfsbob(int curr, int t, vector<int>&vis)
    {
        vis[curr]= true;
        bobmap[curr]=t;
        if(curr==0)
        {
            return true;
        }
        for(auto &neigh: adj[curr])
        {
            if(!vis[neigh])
            {
                if(dfsbob(neigh,t+1,vis))
                {
                    return true;
                }
            }
        }
        bobmap.erase(curr);
        return false;
    }

    void dfsalice(int curr, int t, int income, vector<int>&vis, vector<int>&amount)
    {
        vis[curr]= true;
        if(bobmap.find(curr)==bobmap.end() || t<bobmap[curr])
        {
            income+= amount[curr];
        }
        else if(t==bobmap[curr])
        {
            income+= amount[curr]/2;
        }
        //leaf node..
        if(adj[curr].size()==1 && curr!=0)
        {
            aliceincome= max(aliceincome,income);
        }
        for(auto &neigh: adj[curr])
        {
            if(!vis[neigh])
            {
                dfsalice(neigh,t+1,income,vis,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n= amount.size();
        for(vector<int>&edge: edges)
        {
            int u= edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,false);
        dfsbob(bob,0,vis);

        vis.assign(n,false);//reinitalize vis vector..
        dfsalice(0,0,0,vis,amount);
        return aliceincome;
    }
};