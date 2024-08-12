class Solution {
public:
    //To find kth largest element in array
    //Approach- make a min heap and if size>k pop element, the top will the kth largest in array
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n= nums.size();
        //MIN HEAP..
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.begin()+k);
        for(int i=k;i<n;i++)
        {
            if(pq.top()<nums[i])
            {
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};