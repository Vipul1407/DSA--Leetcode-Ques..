class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int n= cost.size();
        int ans=0;
        sort(begin(cost),end(cost));
        int b= n-1;
        int a= n-2;
        while(true)
        {
            if(b>=0 && a>=0)
            {
                ans+= cost[a];
                ans+= cost[b];
                a-=3;
                b-=3;
            }
            else if(b>=0)
            {
                ans+= cost[b];
                break;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};