class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        vector<vector<int>>dir= {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
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
                int dx= x+dir[d][0];
                int dy= y+dir[d][1];
                if(dx>=0 && dy>=0 && dx<m && dy<n)
                {
                    if(ans[dx][dy]==-1)
                    {
                        ans[dx][dy]= ans[x][y]+1;
                        q.push({dx,dy});
                    }
                }
            }
        }
        return ans;
    }
};