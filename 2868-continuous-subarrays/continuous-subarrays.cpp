class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        //maintaing dequeues of indexes..
        deque<int>maxq;
        deque<int>minq;
        int i=0,j=0;
        int n=nums.size();
        long long ans=0;
        while(j<n)
        {
            //maintaning min element index at back of maxq and min element index at back of minq...
            while(maxq.size() && nums[maxq.back()]<=nums[j])
            {
                maxq.pop_back();
            }
            while(minq.size() && nums[minq.back()]>=nums[j])
            {
                minq.pop_back();
            }
            //pushing index...
            minq.push_back(j);
            maxq.push_back(j);
            //shrinking window..
            while(i<n && nums[maxq.front()]-nums[minq.front()]>2)
            {
                i++;
                if(minq.front()<i)
                {
                    minq.pop_front();
                }
                if(maxq.front()<i)
                {
                    maxq.pop_front();
                }
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};