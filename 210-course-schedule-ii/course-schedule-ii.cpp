class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
            for(auto &neigh: adj[top])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
        if(ans.size()!=n)
        {
            return {};
        }
        return ans;
    }
};