class Solution {
public:
    //METHOD-3
    //OPTIMIZED APPROACH..
    //TC= O(LOG(M*N))
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m= mat.size();
        int n= mat[0].size();
        int l= 0;
        int r= m*n-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            int row= mid/n;
            int col= mid%n;
            if(mat[row][col]==target)
            {
                return true;
            }
            else if(mat[row][col]<target)
            {
                l= mid+1;
            }
            else
            {
                r= mid-1;
            }
        }
        return false;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(M*N)
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m= mat.size();
        int n= mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }

    //METHOD-2
    //BETTER APPROACH..
    //TC= O(M*LOGN)
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m= mat.size();
        int n= mat[0].size();
        for(int i=0;i<m;i++)
        {
            int l= 0;
            int r= n-1;
            while(l<=r)
            {
                int mid= l+(r-l)/2;
                if(mat[i][mid]==target)
                {
                    return true;
                }
                else if(mat[i][mid]<target)
                {
                    l= mid+1;
                }
                else
                {
                    r= mid-1;
                }
            }
        }
        return false;
    }
*/