class Solution {
public:
    //METHOD-1
    //Using Map..
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        unordered_map<int,vector<int>>mp;
        int m= grid.size();
        int n= grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].push_back(grid[i][j]);
            }
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(auto &i:mp)
        {
            //we want to sort in descending order but we will pop from back so sort in ascending order..
            if(i.first>=0)
            {
                sort(begin(i.second),end(i.second));
            }
            //we want to sort in ascending order but we will pop from back so sort in descending order..
            else
            {
                sort(rbegin(i.second),rend(i.second));
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]= mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return ans;
    }
};