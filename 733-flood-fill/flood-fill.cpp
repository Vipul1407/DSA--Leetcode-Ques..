class Solution {
public:
    //METHOD-3
    //DSU..
    class DSU
    {
        public:
        vector<int>par,rank;
        DSU(int n)
        {
            par.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++)
            {
                par[i]=i;
            }
        }
        
        int findupar(int node)
        {
           if(node==par[node])
           {
                return node;
           }
           return par[node]= findupar(par[node]);
        }
        void unionbyrank(int u,int v)
        {
            int up_u= findupar(u);
            int up_v= findupar(v);
            if(up_u == up_v)
            {
                return;
            }
            if(rank[up_u]<rank[up_v])
            {
                par[up_u]= up_v;
            }
            else if(rank[up_v]<rank[up_u])
            {
                par[up_v]= up_u;
            }
            else
            {
                par[up_v]= up_u;
                rank[up_u]++;
            }
        }
    };
    vector<int>dx= {0,1,0,-1};
    vector<int>dy= {1,0,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m= image.size();
        int n=  image[0].size();
        int prev= image[sr][sc];

        DSU dsu(m*n);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx= i*n+j;
                for(int k=0;k<4;k++)
                {
                    int nx= i+ dx[k];
                    int ny= j+ dy[k];
                    if(nx<0 || ny<0 || nx>=m || ny>=n )
                    {
                        continue;
                    }
                    if(image[i][j]==prev && image[nx][ny]==prev)
                    {
                        int nidx= nx*n+ny;
                        dsu.unionbyrank(idx,nidx);
                    }
                }
            }
        }
        int parent= dsu.findupar(sr*n+sc);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx= i*n+j;
                if(dsu.findupar(idx)==parent && image[i][j]==prev)
                {
                    image[i][j] = color;
                }
            }
        }
        image[sr][sc]=color;    
        return image;
    }
};
/*
    //METHOD-1
    //DFS..
    vector<int>dx= {0,1,0,-1};
    vector<int>dy= {1,0,-1,0};
    void dfs(int i,int j,int &prev,int &color, vector<vector<int>>& image, vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        image[i][j]= color;
        for(int k=0;k<4;k++)
        {
            int nx= i+dx[k];
            int ny= j+dy[k];
            if(nx<0 || ny<0 || nx>=image.size() || ny>=image[0].size() || vis[nx][ny])
            {
                continue;
            }
            if(image[nx][ny]==prev)
            {
                dfs(nx,ny,prev,color,image,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m= image.size();
        int n=  image[0].size();
        int prev= image[sr][sc];
        vector<vector<int>>vis(m,vector<int>(n,0));
        dfs(sr,sc,prev,color,image,vis);
        return image;
    }

    //METHOD-2
    //BFS..
    vector<int>dx= {0,1,0,-1};
    vector<int>dy= {1,0,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m= image.size();
        int n=  image[0].size();
        int prev= image[sr][sc];
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
            int x= top.first;
            int y= top.second;

            for(int k=0;k<4;k++)
            {
                int nx= x+ dx[k];
                int ny= y+ dy[k];
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny])
                {
                    continue;
                }
                if(image[nx][ny]==prev)
                {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    image[nx][ny]= color;
                }
            }
        }
        return image;
    }
*/