class Solution {
public:

    bool possible(vector<int>& cand, long long k, int mid)
    {
        long long cnt=0;
        for(auto i:cand)
        {
            cnt+=i/mid;
        }
        return cnt>=k;
    }

    int maximumCandies(vector<int>& cand, long long k) 
    {
        int n=cand.size();
        long long sum=0;
        for(auto i:cand)
        {
            sum+=i;
        }
        if(sum<k)
        {
            return 0;
        }
        int s=1;//as if s=0 then mid can become 0 if e=1 then it will cause division by 0 error
        int e=*max_element(cand.begin(),cand.end());
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(possible(cand,k,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};