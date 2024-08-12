class Solution {
public:
    //To find kth largest element in array
    //Approach- make a min heap and if size>k pop element, the top will the kth largest in array
    int findKthLargest(vector<int>& nums, int k) 
    {
        //MIN HEAP..
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};