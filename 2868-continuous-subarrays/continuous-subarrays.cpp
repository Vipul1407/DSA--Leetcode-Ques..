class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        int n= nums.size();
        priority_queue<pair<int,int>>maxheap;    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        int i=0,j=0;
        long long ans=0;
        while(j<n)
        {
            minheap.push({nums[j],j});
            maxheap.push({nums[j],j});
            while(i<n && (maxheap.top().first-minheap.top().first)>2)
            {
                i++;
                while(!maxheap.empty() && maxheap.top().second<i)
                {
                    maxheap.pop();
                }
                while(!minheap.empty() && minheap.top().second<i)
                {
                    minheap.pop();
                }
            }
            ans+= j-i+1;
            j++;
        }  
        return ans;  
    }
};
