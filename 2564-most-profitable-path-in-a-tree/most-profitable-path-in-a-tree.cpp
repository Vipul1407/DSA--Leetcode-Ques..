class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>mpbob;
    int aliceincome= INT_MIN;
    bool dfsbob(int curr,int t,vector<int>&vis)
    {
        if(curr==0)
        {
            return true;
        }
        vis[curr]=1;
        mpbob[curr]=t;
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
        mpbob.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n= amount.size();
        for(auto &edge:edges)
        {
            int u= edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        dfsbob(bob,0,vis);

        vis.assign(n,0);

        //BFS FOR ALICE----->
        //{curr,t,income}
        queue<vector<int>>q;
        q.push({0,0,0});
        while(!q.empty())
        {
            int curr= q.front()[0];
            int t= q.front()[1];
            int income= q.front()[2];

            vis[curr]=1;
            q.pop();
            if(mpbob.find(curr)==mpbob.end() || t<mpbob[curr])
            {
                income+= amount[curr];
            }
            else if(t==mpbob[curr])
            {
                income+= amount[curr]/2;
            }
            //leaf node...
            if(adj[curr].size()==1 && curr!=0)
            {
                aliceincome= max(aliceincome,income);
            }
            for(auto &neigh: adj[curr])
            {
                if(!vis[neigh])
                {
                    q.push({neigh,t+1,income});
                }
            }
        }
        return aliceincome;
    }
};