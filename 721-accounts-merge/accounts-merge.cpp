class DSU
    {
        public:
        vector<int>par,rank;
        DSU(int n)
        {
            par.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
            {
               par[i]=i; 
            }
        }
        int findupar(int node)
        {
            if(node==par[node])
            {
                return node;
            }
            return par[node]= findupar(par[node]);
        }
        void unionbyrank(int u,int v)
        {
            int pu= findupar(u);
            int pv= findupar(v);
            if(pu==pv)
            {
                return;
            }
            if(rank[pu]<rank[pv])
            {
                par[pu]= pv;
            }
            else if(rank[pv]<rank[pu])
            {
                par[pv]= pu;
            }
            else
            {
                par[pv]= pu;
                rank[pu]++;
            }
        }
    };

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string,int>mp;
        int n= accounts.size(); 

        DSU ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string email= accounts[i][j];
                if(mp.find(email)!=mp.end())
                {
                    ds.unionbyrank(i,mp[email]);
                }
                else
                {
                    mp[email]=i;
                }
            }
        }   
        vector<vector<string>>ans;
        unordered_map<int,vector<string>>vec;
        for(auto i:mp)
        {
            string email= i.first;
            int node= i.second;
            int node_par= ds.findupar(node);
            vec[node_par].push_back(email);
        }
        for(auto i:vec)
        {
            auto temp= i.second;
            sort(begin(temp),end(temp));
            temp.insert(begin(temp),accounts[i.first][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};