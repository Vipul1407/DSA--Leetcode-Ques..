class Solution {
public:
    int dfs(int i, unordered_map<int,vector<int>>&adj2, vector<int>&vis2, int k, int &n)
    {
        if(k<0)
        {
            return 0;
        }
        if(vis2[i]==1)
        {
            return 0;
        }
        int cnt=1;//curr node..
        vis2[i]=1;
        for(auto &neigh: adj2[i])
        {
            if(!vis2[neigh])
            {
                cnt+= dfs(neigh,adj2,vis2,k-1,n);
            }
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        //tree2....
        int n= edges2.size()+1;
        unordered_map<int,vector<int>>adj2;
        for(auto i:edges2)
        {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            vector<int>vis2(n,0);
            maxi= max(maxi,dfs(i,adj2,vis2,k-1,n));//we want k-1 distance nodes only as we will connect 1edge to tree1 
        }
        
        //tree1...
        n= edges1.size()+1;
        vector<int>ans(n,0);
        unordered_map<int,vector<int>>adj1;
        for(auto i:edges1)
        {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            vector<int>vis1(n,0);
            ans[i]= dfs(i,adj1,vis1,k,n)+ maxi;//we want all k nodes..
        }
        return ans;
    }
};