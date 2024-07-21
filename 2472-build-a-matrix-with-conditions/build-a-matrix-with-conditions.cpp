// Approach 2 -> BFS

// TC= O[ 2* (V+E)] + O(topRow.size()^2)

class Solution{
public:
   vector<int> topoSort(vector<vector<int>> &vec, int k)
   {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(k+1, 0);

        // create adj list from adj matrix..
        for(vector<int> &it: vec)
        {
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);  // create directed graph
            indegree[v]++;
        }

        queue<int> q;
        vector<int> topo;
        int cnt= 0;

        for(int i=1; i<=k; i++)
        {
            if(indegree[i]== 0)
            {
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            topo.push_back(node);

            for(auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]== 0)
                {
                    q.push(neighbour);
                    cnt++;
                }
            }
        }
        
        // If cycle is present...
        if(cnt != k)
        {
            return {};
        }

    return topo;
   }

  
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col)
    {  
        vector<int> topoRow= topoSort(row,k);
        vector<int> topoCol= topoSort(col,k);

        vector<vector<int>> ans(k, vector<int> (k, 0));

        // Topological sort valid for DAG(Directed Acyclic Graph)
        // if graph contains cycle... we cannot make matrix..

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        for(int i=0; i<topoRow.size(); i++)
        {
            for(int j=0; j<topoCol.size(); j++)
            {
                  if(topoRow[i]== topoCol[j])
                  {
                      ans[i][j]= topoRow[i]; // topoCol[j];
                  }
            }
        }
     return ans;
    }
};






// Ques of Topological Sort

// Approach 1 - DFS -> Beats 27.61 % users 
// TC= O(V + E) > For directed graph topological sort

// Overall TC= O [2*(V+E)] + O(topoRow.size()^2)

/*

class Solution {
public:
   bool dfs(int i,unordered_map<int,vector<int>> &adj, vector<bool> &visited, stack<int> &st, vector<bool> &pathVisited)
   {
        visited[i]= true;
        pathVisited[i]= true;

        for(auto neighbour: adj[i])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour, adj, visited, st, pathVisited))
                {
                    return true;
                }
            }
            
            // cycle found, if it is already visited and pathVisited...
            else if(pathVisited[neighbour])
            {
               return true;
            }
        }

        st.push(i);
        pathVisited[i]= false;
        return false;

   }

    vector<int> topoSort(vector<vector<int>>& vec, int k)
    {
        // Create adj list from adj edges.
        unordered_map<int,vector<int>> adj;

        for(vector<int> it: vec)
        {
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v); // making directed graph..
        }

        // we have to take account of value rather than index..
         vector<bool> visited(k+1,false);
         vector<bool> pathVisited(k+1, false);
         stack<int> st;
         
         for(int i=1; i<=k; i++)
         {
            if(!visited[i])
            {
                // if cycle present, NOT possible to generate matrix..
                if(dfs(i,adj,visited,st,pathVisited))
                {
                    return {};
                }
            }
         }

        vector<int> topo;
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        } 
      return topo;
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col)
    {  
        vector<int> topoRow= topoSort(row,k);
        vector<int> topoCol= topoSort(col,k);
        
        // Topological sort valid for DAG(Directed Acyclic Graph)
        // if graph contains cycle... we cannot make matrix..

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        vector<vector<int>> ans(k, vector<int> (k,0));
        
        for(int i=0; i<topoRow.size(); i++)
        {
            for(int j=0; j<topoCol.size(); j++)
            {
                if(topoRow[i]== topoCol[j])
                {
                    ans[i][j]= topoRow[i]; // topoCol[j];
                }
            }
        }
    return ans;
    }
};


*/