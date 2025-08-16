class Solution {
public:
    bool possi(vector<int>& ranks, int cars, long long mid)
    {
        //t= r*n^2 
        //n= sqrt(t/r)
        int cnt=0;
        for(auto r:ranks)
        {
            //mid is t and r is rank
            cnt+= sqrt(mid/r);
            if(cnt>=cars)
            {
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int n= ranks.size();
        long long l=1;
        long long r= *max_element(begin(ranks),end(ranks));
        r*= cars;
        r*= cars;
        long long ans= r;
        while(l<=r)
        {
            long long mid= l+(r-l)/2;
            if(possi(ranks,cars,mid))
            {
                ans= mid;
                r= mid-1;//searching for smaller minutes...
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};