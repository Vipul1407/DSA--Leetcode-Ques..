class Solution {
public:
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
};