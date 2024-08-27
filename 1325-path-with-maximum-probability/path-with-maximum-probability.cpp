class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int s, int e) 
    {
        unordered_map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({edges[i][1],prob[i]});
            mp[edges[i][1]].push_back({edges[i][0],prob[i]});
        }
        //max prob. needed -->MAX HEAP
        priority_queue<pair<double,int>>pq;
        vector<double>store(n,0.0);
        store[s]=1.0;
        pq.push({1.0,s});
        while(!pq.empty())
        {
            double wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            if(wt< store[node])
            {
                continue;
            }
            for(auto i:mp[node])
            {
                double p= i.second;
                int neighbour= i.first;
                if(p*wt > store[neighbour])
                {
                    store[neighbour]= p*wt;
                    pq.push({store[neighbour], neighbour});
                }
            }
        }
        return store[e];
    }
};