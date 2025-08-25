class Solution {
public:
    //METHOD-1
    //BFS approach
    //TC= O(M*N) since we are inserting every element if not want to insert then O(M+N)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<int>ans;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;
        ans.push_back(mat[0][0]);
        bool flip= 1;

        while(!q.empty())
        {
            vector<int>vec;
            int size= q.size();
            while(size--)
            {
                int x= q.front().first;
                int y= q.front().second;
            
                if(x+1<m && vis[x+1][y]==0)
                {
                    vec.push_back(mat[x+1][y]);
                    q.push({x+1,y});
                    vis[x+1][y]=1;
                } 
                if(y+1<n && vis[x][y+1]==0)
                {
                    vec.push_back(mat[x][y+1]);
                    q.push({x,y+1});
                    vis[x][y+1]=1;
                }
                q.pop();
            } 
            if(flip)
            {
                reverse(vec.begin(),vec.end());
            }
            for(auto &j:vec)
            {
                ans.push_back(j);
            }
            flip= !flip;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //Map approach
    //TC= O(M*N*LOG(M+N))
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flip= 1;
        for(auto &i:mp)
        {
            vector<int>vec= i.second;
            if(flip)
            {
                reverse(vec.begin(),vec.end());
            }
            for(auto &j:vec)
            {
                ans.push_back(j);
            }
            flip= !flip;
        }
        return ans;
    }
*/