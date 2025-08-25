class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flip= 1;
        for(auto &i:mp)
        {
            vector<int>vec= i.second;
            if(flip)
            {
                reverse(vec.begin(),vec.end());
            }
            for(auto &j:vec)
            {
                ans.push_back(j);
            }
            flip= !flip;
        }
        return ans;
    }
};