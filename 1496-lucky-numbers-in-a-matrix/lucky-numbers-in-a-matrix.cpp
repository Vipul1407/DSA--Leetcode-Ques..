class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) 
    {
        int m= mat.size();//row
        int n= mat[0].size();//col

        vector<int>rowmin(m);
        vector<int>colmax(n);
        vector<int>ans;

        for(int i=0;i<m;i++)
        {
            int rmin= INT_MAX;
            for(int j=0;j<n;j++)
            {
                rmin= min(rmin, mat[i][j]);
            }
            rowmin[i]= rmin;
        }

        for(int j=0;j<n;j++)
        {
            int cmax= INT_MIN;
            for(int i=0;i<m;i++)
            {
                cmax= max(cmax, mat[i][j]);
            }
            colmax[j]= cmax;
        }

        unordered_set<int>st(colmax.begin(),colmax.end());
        for(auto i: rowmin)
        {
            if(st.find(i)!=st.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};