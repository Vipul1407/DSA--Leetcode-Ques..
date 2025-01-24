class Solution {
public:
    //METHOD-1
    //DFS..
    bool detectcycle(int i,vector<vector<int>>& graph,vector<int>&vis,vector<int>&currpath)
    {
        vis[i]=1;
        currpath[i]=1;
        for(int v:graph[i])
        {
            if(!vis[v] && detectcycle(v,graph,vis,currpath))
            {
                return true;
            }
            //visited bhi h and currpath me bhi h true h mtlb cycle h becoz phir se hmne usse visited kiya h..
            else if(currpath[v]==1)
            {
                return true;
            }
        }
        currpath[i]= false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n= graph.size();
    
        vector<int>vis(n,0);
        vector<int>currpath(n,0);
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            //if its not lying in curr path..
            if(!vis[i])
            {
                detectcycle(i,graph,vis,currpath);
            }
        }

        //not in currpath hence no cycle==> in safe/terminal state... 
        for(int i=0;i<n;i++)
        {
            if(currpath[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};