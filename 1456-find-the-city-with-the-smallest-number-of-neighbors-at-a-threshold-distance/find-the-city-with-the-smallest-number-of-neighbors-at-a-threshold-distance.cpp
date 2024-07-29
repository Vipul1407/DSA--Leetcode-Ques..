class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int td) 
    {
        vector<pair<int,int>>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        set<pair<int,int>>st;
        int city=0;
        int mincnt= n+1;
        for(int i=0;i<n;i++)
        {
            vector<int>dis(n,INT_MAX);
            st.insert({0,i});
            dis[i]=0;
            while(!st.empty())
            {
                auto top= *st.begin();
                int d= top.first;
                int node= top.second;
                st.erase(top);
                for(auto i:adj[node])
                {
                    int neigh= i.first;
                    int wt= i.second;
                    if(d+wt< dis[neigh])
                    {
                        if(dis[neigh]!=INT_MAX)
                        {
                            st.erase({dis[neigh],neigh});
                        }
                        dis[neigh]= d+wt;
                        st.insert({dis[neigh],neigh});
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(dis[i]<=td)
                {
                    cnt++;
                }
            }
            if(cnt<= mincnt)
            {
                mincnt= cnt;
                city= i;
            }
        }
        return city;
    }
};