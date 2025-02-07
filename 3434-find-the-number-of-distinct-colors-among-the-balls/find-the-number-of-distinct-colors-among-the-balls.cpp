class Solution {
public:
    vector<int> queryResults(int lim, vector<vector<int>>& arr) 
    {
        unordered_map<int,int>mp;
        unordered_map<int,int>np;
        vector<int>ans;
        for(auto i:arr)
        {
            int ball=i[0];
            int col=i[1];
            if(mp.count(ball))
            {
                int existcol=mp[ball];
                if(np[existcol]==1)
                {
                    np.erase(existcol);
                }
                else
                {
                    np[existcol]--;
                }
            }
            mp[ball]=col;
            np[col]++;
            ans.push_back(np.size());
        }
        return ans;
    }
};