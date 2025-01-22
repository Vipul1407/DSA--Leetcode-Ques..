class Solution {
public:
    //Same as Map of Highest Peak....
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        vector<int>dirx= {0,1,0,-1};
        vector<int>diry= {1,0,-1,0};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //we have to count distance of nearest 0
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(q.size())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int dx= x+dirx[d];
                int dy= y+diry[d];
                if(dx>=0 && dx<m && dy>=0 && dy<n && ans[dx][dy]==-1)
                {
                    ans[dx][dy]= ans[x][y]+1;//we have find adjacent 0
                    q.push({dx,dy});
                }
            }
        }
        return ans;
    }
}; 