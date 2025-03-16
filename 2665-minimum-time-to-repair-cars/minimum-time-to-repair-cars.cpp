class Solution {
public:
    //MINIMIZE THE MAXIMUM TIME TAKEN FROM ALL CASES...
    //BINARY SEARCH..
    bool possi(long long mid,vector<int>& ranks, int cars)
    {
        //no of cars that can be manufactured within given time..
        long long cnt=0;
        //since t= r*n^2
        // n= sqrt(t/r)--> no of cars 
        //mid is the that max time..
        for(int i=0;i<ranks.size();i++)
        {
            //given that ranks[i]>=1 always..
            cnt+= (long long)sqrt(mid/ranks[i]);
        }
        return cnt>= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) 
    {
        //maxtime...
        long long r= 1LL* (*max_element(ranks.begin(),ranks.end()))*cars*cars;
    
        //mintime... will not be min_element*cars*cars as we can do the work simultaneously.. so we can get minimum..
        long long l= 1;
        long long ans=r;
        while(l<=r)
        {
            long long mid= l+(r-l)/2;
            if(possi(mid,ranks,cars))
            {
                ans= mid;
                r= mid-1;//to get smaller ans..
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};