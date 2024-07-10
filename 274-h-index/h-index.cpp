class Solution {
public:
    bool possible(vector<int>& cit, int k)
    {
        int cnt=0;
        for(auto i:cit)
        {
            if(i>=k)
            {
                cnt++;
            }
        }
        return cnt>=k;
    }
    int hIndex(vector<int>& cit) 
    {
       int low= 0;
       int high= cit.size();
       int ans=0;
       while(low<=high)
        {
            int mid= (low+high)/2;
            if(possible(cit,mid))
            {
                ans= mid;
                low= mid+1;
            }
            else
            {
                high= mid-1;
            }
        } 
        return ans;
    }
};