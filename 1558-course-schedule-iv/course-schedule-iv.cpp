class Solution {
public:
    //METHOD-1
    //BFS..
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        queue<int>q;
        unordered_map<int,unordered_set<int>>topo;
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto top= q.front();
            q.pop();
            for(auto i:adj[top])
            {
                topo[i].insert(top);
                //transitivity.. check in mp..
                for(auto j:topo[top])
                {
                    topo[i].insert(j);
                }
                indegree[i]--;
                if(indegree[i]==0) 
                {
                    q.push(i);
                }
            }
        }

        vector<bool>ans;
        for(auto i:queries)
        {
            int src= i[0];
            int dest= i[1];
            ans.push_back(topo[dest].contains(src));
        }
         
        return ans;
    }
};