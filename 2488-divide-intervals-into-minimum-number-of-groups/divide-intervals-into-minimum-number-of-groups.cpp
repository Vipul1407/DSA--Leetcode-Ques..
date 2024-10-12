class Solution {
public:
    //OPTIMIZED USING PRIORITY QUEUE..
    int minGroups(vector<vector<int>>& inter) 
    {
        int n=inter.size();
        //min heap storing departure
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(inter.begin(),inter.end());
        
        for(auto i:inter)
        {
            int arri= i[0];
            int dep= i[1];
            if(pq.size() && arri>pq.top())
            {
                pq.pop();
            }
            pq.push(dep);
        }
        return pq.size();
    }
};