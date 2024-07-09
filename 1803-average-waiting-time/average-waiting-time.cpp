class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) 
    {
        double ans=0;
        int n=cust.size();

        int ft=0;
        int at=0;
        for(auto i:cust)
        {
            at= i[0];
            ft= max(at,ft)+ i[1];
            ans+= ft-at;
        }
        return ans/n;
    }
};