class Solution {
public:
    //METHOD-2
    //GREEDY
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int>vec(26,0);
        for(auto i:tasks)
        {
            vec[i-'A']++;
        }
        sort(begin(vec),end(vec));
        int gadhe= vec[25]-1;
        int idle= gadhe*n;
        for(int i=24;i>=0;i--)
        {
            if(vec[i]==0)
            {
                continue;
            }
            idle-= min(vec[i],gadhe);
        }
        if(idle>0)
        {
            return tasks.size()+idle;
        }
        return tasks.size();
    }
};
/*
    //METHOD-1
    //PRIORITY_QUEUE
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<int>pq;
        int ans=0;
        vector<int>vec(26,0);
        for(auto i:tasks)
        {
            vec[i-'A']++;
        }
        for(int i=0;i<26;i++)
        {
            if(vec[i]>0)
            {
                pq.push(vec[i]);
            }
        }
        while(pq.size())
        {
            vector<int>temp;
            for(int i=0;i<=n;i++)
            {
                if(pq.size())
                {
                    int freq= pq.top();
                    pq.pop();
                    temp.push_back(--freq);
                }
                else
                {
                    break;
                }
            }
            for(auto i:temp)
            {
                if(i>0)
                    pq.push(i);
            }
            if(pq.empty())
            {
                ans+= temp.size();
            }
            else
            {
                ans+= n+1;
            }
        }
        return ans;
    }
*/