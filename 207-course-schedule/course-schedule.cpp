class Solution {
public:
    //METHOD-1
    //BFS using Kahn Algo..
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                cnt++;
            }
        }
        while(q.size())
        {
            auto top=q.front();
            q.pop();
            for(auto neigh: adj[top])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
};