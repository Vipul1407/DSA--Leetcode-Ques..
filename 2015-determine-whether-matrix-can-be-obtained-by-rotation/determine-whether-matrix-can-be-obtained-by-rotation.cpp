class Solution {
public:
    void rotate(vector<vector<int>>& mat)
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>temp= mat;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int r= j;
                int c= n-1-i;
                temp[r][c]= mat[i][j];
            }
        }
        mat= temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        int m= mat.size();
        int n= mat[0].size();
        for(int k=0;k<=3;k++)
        {
            bool flag= 1;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][j]!=target[i][j])
                    {
                        flag= 0;
                        break;
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
            if(flag)
            {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};