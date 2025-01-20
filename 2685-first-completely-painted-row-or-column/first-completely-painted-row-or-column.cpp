class Solution {
public:

    //METHOD-1
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        //to store ki konsa element konse index pe present h matrix me..
        unordered_map<int,pair<int,int>>mp;
        int m= mat.size();
        int n= mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<arr.size();i++)
        {
            if(++row[mp[arr[i]].first]==n)
            {
                return i;
            }
            if(++col[mp[arr[i]].second]==m)
            {
                return i;
            }
        }
        return 0;
    }
};