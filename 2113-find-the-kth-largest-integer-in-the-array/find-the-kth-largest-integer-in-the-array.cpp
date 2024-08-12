class Solution {
public:

    string kthLargestNumber(vector<string>& nums, int k) 
    {
        //help to make min heap 
        auto cmp= [](string&a, string&b)
        {
            if(a.size()==b.size())
            {
                return a>b;
            }
            return a.length()>b.length();
        };
        //forming a min heap with given cmo function..
        priority_queue<string,vector<string>,decltype(cmp)>pq(cmp);
        int n= nums.size();

        for(auto it:nums)
        {
            pq.push(it);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};