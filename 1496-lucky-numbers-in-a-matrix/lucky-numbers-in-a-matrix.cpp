class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) 
    {
        int m= mat.size();//row
        int n= mat[0].size();//col

        int rmin_max= INT_MIN;
        for(int i=0;i<m;i++)
        {
            int rmin= INT_MAX;
            for(int j=0;j<n;j++)
            {
                rmin= min(rmin, mat[i][j]);
            }
            rmin_max= max(rmin_max, rmin);
        }

        int cmax_min= INT_MAX;
        for(int j=0;j<n;j++)
        {
            int cmax= INT_MIN;
            for(int i=0;i<m;i++)
            {
                cmax= max(cmax, mat[i][j]);
            }
            cmax_min= min(cmax_min, cmax);
        }

        if(rmin_max == cmax_min)
        {
            return {rmin_max};
        }
        else
        {
            return {};
        }
    }
};