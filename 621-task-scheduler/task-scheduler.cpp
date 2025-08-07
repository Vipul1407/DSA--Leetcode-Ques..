class Solution {
public:
    //METHOD-1
    //MAX HEAP..
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int>freq(26,0);
        for(auto i:tasks)
        {
            freq[i-'A']++;
        }
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
            //run loop n+1 times..
            for(int i=0;i<=n;i++)
            {
                if(pq.size())
                {
                    int cnt= pq.top();
                    temp.push_back(--cnt);
                    pq.pop();
                }
                else
                {
                    break;
                }
            }
            for(auto i:temp)
            {
                if(i>0)
                {
                    pq.push(i);
                }
                else
                {
                    break;
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