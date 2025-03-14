class DSU
{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findupar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]= findupar(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int up_u= findupar(u);
        int up_v= findupar(v);
        if(up_u==up_v)
        {
            return;
        }
        if(rank[up_u]<rank[up_v])
        {
            parent[up_u]= up_v;
        }
        else if(rank[up_u]>rank[up_v])
        {
            parent[up_v]= up_u;
        }
        else
        {
            parent[up_v]= up_u;
            rank[up_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) 
    {
        unordered_map<string,int>mp;
        int n= acc.size();
        DSU ds(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<acc[i].size();j++)
            {
                string email= acc[i][j];
                if(mp.find(email)!=mp.end())
                {
                    ds.unionbyrank(i,mp[email]);
                }
                else
                {
                    mp[email]= i;
                }
            }
        }
        vector<vector<string>>merged(n);
        
        for(auto i:mp)
        {
            int par= ds.findupar(i.second);
            merged[par].push_back(i.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(merged[i].size()==0)
            {
                continue;
            }
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for(auto j:merged[i])
            {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};