class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n= nums1.size();
        vector<long long>ans(n,0);
        vector<vector<int>>vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]= {nums1[i],i,nums2[i]};
        }        
        sort(vec.begin(),vec.end());

        //min heap..
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            //agar dono sum same h to jo prev ans me pdha h vhi rkh de..
            if(j>0 && vec[j-1][0]==vec[j][0])
            {
                ans[vec[j][1]]= ans[vec[j-1][1]];
            }
            else
            {
                ans[vec[j][1]]= sum;
            }
           
            pq.push(vec[j][2]);
            sum+= vec[j][2];
            if(pq.size()>k)
            {
                sum-= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
// TC= O(N^2* LOGN)
vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n= nums1.size();
        vector<long long>ans(n,-1);
        for(int i=0;i<n;i++)
            {
                priority_queue<long long>maxheap;
                for(int j=0;j<n;j++)
                {
                    if(i!=j && nums1[j]<nums1[i])
                    {
                        maxheap.push(nums2[j]);
                    }
                }
                long long sum=0;
                int cnt=k;
                while(cnt-- && maxheap.size())
                    {
                        sum+= maxheap.top();
                        maxheap.  pop();
                    }
                ans[i]= sum;
            }
        return ans;
    }
*/

