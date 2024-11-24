class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        long long sum=0;
        int cntnegative=0;
        int low= INT_MAX;
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                if(j<0)
                {
                    cntnegative++;
                }
                sum+= abs(j);
                low= min(low,abs(j));
            }
        }    
        return cntnegative%2==0 ? sum: sum-2*abs(low);
    }
};