class Solution {
public:
    bool possi(int i,int j,vector<vector<int>>& mat)
    {
        int m= mat.size();
        int n= mat[0].size();
        for(int k=0;k<m;k++)
        {
            if(k!=i && mat[k][j]!=0)
            {
                return false;
            }
        }
        for(int k=0;k<n;k++)
        {
            if(k!=j && mat[i][k]!=0)
            {
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    if(possi(i,j,mat))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};