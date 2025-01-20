class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
    //TC= O(M*N)
    //SC=O(M+N)
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        //to store element,index of arr...
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        int rowpaint=m*n;
        for(int row=0;row<m;row++)
        {
            int maxirow=0;
            for(int col=0;col<n;col++)
            {
                maxirow= max(maxirow, mp[mat[row][col]]);   
            }
            rowpaint= min(rowpaint,maxirow);
        }

        int colpaint=m*n;
        for(int col=0;col<n;col++)
        {
            int maxicol=0;
            for(int row=0;row<m;row++)
            {
                maxicol= max(maxicol, mp[mat[row][col]]);
            }
            colpaint= min(colpaint,maxicol);
        }
        return min(rowpaint,colpaint);
    }
};
/*
// METHOD-1
// TC=O(M+N)
// SC= O(M*N)+O(M+N)
int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    // to store ki konsa element konse index pe present h matrix me..
    unordered_map<int, pair<int, int>> mp;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[mat[i][j]] = {i, j};
        }
    }
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        // row ka size agar col.size() to return i
        if (++row[mp[arr[i]].first] == n)
        {
            return i;
        }
        // col ka size row.size() to return i
        if (++col[mp[arr[i]].second] == m)
        {
            return i;
        }
    }
    return 0;
}
*/