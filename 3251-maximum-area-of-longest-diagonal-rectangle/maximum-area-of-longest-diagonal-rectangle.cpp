class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int ans=0;
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
};