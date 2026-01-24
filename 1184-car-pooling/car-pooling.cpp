class Solution {
public:
    //METHOD-1
    //USING MIN HEAP..
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int n= trips.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:trips)
        {
            pq.push({i[1],i[0]});
            pq.push({i[2],-i[0]});
        }
        while(pq.size())
        {
            auto top= pq.top().second;
            pq.pop();

            capacity-= top;
            if(capacity<0)
            {
                return false;
            }
        }
        return true;
    }
};