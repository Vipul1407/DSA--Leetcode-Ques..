class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int ans=0;
        int maxdia=0;
        for(auto i:dimensions)
        {
            int dialen= i[0]*i[0]+i[1]*i[1];
            if(dialen>maxdia)
            {
                maxdia= dialen;
                ans=i[0]*i[1];
            }
            else if(dialen==maxdia)
            {
                ans= max(ans,i[0]*i[1]);
            }
        }
        return ans;
    }
};
/*
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int ans=0;
        //float can also be used
        double maxdia=0;
        for(auto i:dimensions)
        {
            double dialen= sqrt(i[0]*i[0]+i[1]*i[1]);
            if(dialen>maxdia)
            {
                maxdia= dialen;
                ans=i[0]*i[1];
            }
            else if(dialen==maxdia)
            {
                ans= max(ans,i[0]*i[1]);
            }
        }
        return ans;
    }
*/