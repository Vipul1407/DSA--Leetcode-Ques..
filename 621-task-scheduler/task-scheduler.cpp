class Solution {
public:
    //METHOD-1
    //MAX HEAP..(PRIORITY_QUEUE)
    //TC= O(N*LOG26)
    int leastInterval(vector<char>& task, int n) 
    {
        vector<int>freq(26,0);
        for(auto i:task)
        {
            freq[i-'A']++;
        }
        //max heap storing freq..
        priority_queue<int>pq;
        for(auto i:freq)
        {
            if(i>0)
            {
                pq.push(i);
            }
        }
        int time=0;
        while(pq.size())
        {
            vector<int>temp;
            //run loop n+1 times
            for(int i=1;i<=n+1;i++)
            {
                if(pq.size())
                {
                    int cnt= pq.top();
                    pq.pop();
                    temp.push_back(--cnt);
                }
                else
                {
                    break;
                }
            }
            for(auto &f:temp)
            {
                if(f>0)
                {
                    pq.push(f);
                }
            }
            if(pq.size())
            {
                time+= n+1;
            }
            else
            {
                time+= temp.size();
            }
        }
        return time;
    }
};