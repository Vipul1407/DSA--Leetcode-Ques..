class Solution {
public:
    //METHOD-2
    //OPTIMIZED TOPOLOGICAL SORTING..
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supp) 
    {
        int n= rec.size();
        unordered_set<string>st;
        queue<int>q;
        vector<int>indegree(n,0);
        for(auto i:supp)
        {
            st.insert(i);
        }
        unordered_map<string,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ing[i].size();j++)
            {
                //agar set me ni mila to..
                if(st.find(ing[i][j])==st.end())
                {
                    adj[ing[i][j]].push_back(i);
                    indegree[i]++;
                }
            }
        }
        //apply khan Algo (BFS- Toposort..)
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<string>ans;
        while(q.size())
        {
            int i= q.front();
            q.pop();
            ans.push_back(rec[i]);

            for(int &idx: adj[rec[i]])
            {
                if(--indegree[idx]==0)
                {
                    q.push(idx);
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supp) 
    {
        int n= rec.size();
        unordered_set<string>st;
        for(auto i:supp)
        {
            st.insert(i);
        }
        vector<string>ans;
        vector<int>cooked(n,0);
        int cnt=n;
        while(cnt--)
        {
            for(int i=0;i<n;i++)
            {
                if(cooked[i]==1)
                {
                    continue;
                } 
                bool canmake= true;
                for(int j=0;j<ing[i].size();j++)
                {
                    if(st.find(ing[i][j])==st.end())
                    {
                        canmake= false;
                        break;
                    }
                }
                if(canmake==true)
                {
                    cooked[i]=1;
                    st.insert(rec[i]);
                    ans.push_back(rec[i]);
                }
            }
        }
        return ans;
    }
*/