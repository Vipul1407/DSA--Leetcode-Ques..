class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rsum, vector<int>& csum) 
    {
        int m= rsum.size();
        int n= csum.size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        int row=0;
        int col=0;
        while(row<m && col<n)
        {
            int k= min(rsum[row],csum[col]);
            mat[row][col]= k;
            rsum[row]-=k;
            csum[col]-=k;
            if(rsum[row]==0)
            {
                row++;
            }
            if(csum[col]==0)
            {
                col++;
            }
        }
        return mat;
    }
};