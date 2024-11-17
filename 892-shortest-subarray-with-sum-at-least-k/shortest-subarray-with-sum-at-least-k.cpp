class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n= nums.size();
        deque<int>dq;//storing index..
        vector<long long>pref(n ,0);//maintaining a commulative sum array...
        int minlen= INT_MAX;

        //iterating on prefix vector..
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                pref[0]= nums[0];
            }
            else
            {
                pref[j]= pref[j-1]+ nums[j];
            }
            //if pref[j] already >=k
            if(pref[j]>=k)
            {
                minlen= min(minlen,j+1);
            }
            //front------back  ==>deque
            //shrinking the window..
            while(dq.size() && pref[j]-pref[dq.front()]>=k)
            {
                minlen= min(minlen,j-dq.front());
                dq.pop_front();
            }
            //we are maintaing a monotonic deque..
            //if curr sum i.e pref[j]<= jo pichla sum tha i.e pref[dq.back()] to pop krta rh..
            //becoz we need minlen
            while(dq.size() && pref[j]<=pref[dq.back()])
            {
                dq.pop_back();
            }
            //push index at each iteration at dq.back...
            dq.push_back(j);
        }
        return minlen==INT_MAX? -1:minlen;
    }
};