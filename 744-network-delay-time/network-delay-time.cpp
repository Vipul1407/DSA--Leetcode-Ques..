class Solution {
public:
    //METHOD-2
    //USING SET
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>ans(n+1,INT_MAX);
        int size= times.size();
        for(auto i:times)
        {
            int u= i[0];
            int v= i[1];
            int w= i[2];
            adj[u].push_back({v,w});
        }
        set<pair<int,int>>st;
        st.insert({0,k});
        ans[k]=0;
        while(st.size())
        {
            auto top= *(st.begin());
            int w= top.first;
            int neigh= top.second;
            st.erase(top);
            for(auto i:adj[neigh])
            {
                int d= i.second;
                int node= i.first;
                if(d+w< ans[node])
                {
                    if(ans[node]!=INT_MAX)
                    {
                        st.erase({ans[node],node});
                    }
                    ans[node]= d+w;
                    st.insert({ans[node],node});
                }
            }
        }
        int maxi= INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==INT_MAX)
            {
                return -1;
            }
            maxi= max(maxi,ans[i]);
        }
        return maxi;
    }
};
/*
    //METHOD-1
    //USING PRIORITY_QUEUE
    //TC= O(NLOGN)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>ans(n+1,INT_MAX);
        int size= times.size();
        for(auto i:times)
        {
            int u= i[0];
            int v= i[1];
            int w= i[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        ans[k]=0;
        while(pq.size())
        {
            int w= pq.top().first;
            int neigh= pq.top().second;
            pq.pop();
            for(auto i:adj[neigh])
            {
                int d= i.second;
                int node= i.first;
                if(d+w< ans[node])
                {
                    ans[node]= d+w;
                    pq.push({ans[node],node});
                }
            }
        }
        int maxi= INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==INT_MAX)
            {
                return -1;
            }
            maxi= max(maxi,ans[i]);
        }
        return maxi;
    }
*/