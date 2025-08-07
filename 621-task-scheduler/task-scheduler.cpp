class Solution {
public:
    //METHOD-2
    //WITHOUT USING HEAP..
    //TC= O(N) assuming sorting in O(1)
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int>freq(26,0);
        for(auto i:tasks)
        {
            freq[i-'A']++;
        }
        sort(begin(freq),end(freq));
        int gadhe= freq[25]-1;
        int idle= gadhe*n;
        for(int i=24;i>=0;i--)
        {
            if(freq[i]==0)
            {
                continue;
            }
            idle-= min(gadhe,freq[i]);
        }
        if(idle>0)
        {
            return tasks.size()+idle;
        }
        else
        {
            return tasks.size();
        }
    }
};
/*
    //METHOD-1
    //MAX HEAP..
    //TC= O(N*LOG(26))
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
*/