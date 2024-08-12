class KthLargest {
public:
    //to find kth largest element--> 
    //Approach- make a min heap, insert elements into it, it size>k then pop, then the top element will be our largest one
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) 
    {
        this->k=k;
        for(auto i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) 
    {
        pq.push(val);
        if(pq.size()>k)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */