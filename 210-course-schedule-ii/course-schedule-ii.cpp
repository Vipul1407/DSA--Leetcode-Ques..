class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        vector<int> ans;
        for (auto i : prerequisites)
        {
            // 0->1
            // then 1 should come before 0..
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for (int i = 0; i < n ; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (q.size())
        {
            auto i = q.front();
            q.pop();
            for (auto &neigh : adj[i])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
        if (ans.size() != n)
        {
            return {};
        }
        return ans;
    }
};