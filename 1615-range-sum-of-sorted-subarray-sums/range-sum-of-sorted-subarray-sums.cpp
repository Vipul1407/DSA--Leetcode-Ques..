class Solution {
public:
    #define MOD 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        //Min Heap
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum= (sum+nums[j])%MOD;
                pq.push(sum);
            }
        }

        //min heap h isliye left-1 tk nikal lenge becoz hmko left-->right tk ka sum needed h
        for(int i=0;i<left-1;i++)
        {
            pq.pop();
        }
        int ans=0;
        //left-->right(included) tk ka sum needed h 
        for(int i=left;i<=right;i++)
        {
            ans= (ans+pq.top())%MOD;
            pq.pop();
        }
        return ans;
    }
};