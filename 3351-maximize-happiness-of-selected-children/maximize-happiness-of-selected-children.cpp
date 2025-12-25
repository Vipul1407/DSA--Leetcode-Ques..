class Solution {
public:
    //METHOD-2
    //MAX HEAP..
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long ans=0;
        priority_queue<int>pq(begin(happiness),end(happiness));

        int cnt=0;
        while(pq.size())
        {
            auto top= pq.top();
            pq.pop();
            if(k>0 && top-cnt>0)
            {
                ans+= top-cnt;
                cnt++;
                k--;
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //SORTING 
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long ans=0;
        sort(rbegin(happiness),rend(happiness));
        int cnt=0;
        for(auto i:happiness)
        {
            if(k>0)
            {
                if(i-cnt<=0)
                {
                    return ans;
                }
                ans+= i-cnt;
                cnt++;
                k--;
            }
        }
        return ans;
    }
*/