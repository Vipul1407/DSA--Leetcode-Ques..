class Solution {
public:
    //METHOD-2
    // Without Using Heap..
    //TC= O(N)
    int leastInterval(vector<char>& task, int n) 
    {
        vector<int>freq(26,0);
        for(auto i:task)
        {
            freq[i-'A']++;
        }
        sort(freq.begin(),freq.end());
        int time=0;
        //maxfreq= freq[25]
        int gadhe= freq[25]-1;
        int idle= gadhe*n;
        for(int i=24;i>=0;i--)
        {
            if(freq[i]==0)
            {
                break;
            }
            idle-= min(gadhe,freq[i]);
        }
        if(idle>0)
        {
            return task.size()+idle;
        }
        else
        {
            return task.size();
        }
    }
};
/*
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
*/