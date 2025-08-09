class Solution {
public:
    //METHOD-2
    //Without Max Heap..
    string reorganizeString(string s) 
    {
        vector<int>freq(26,0);
        int n= s.size();
        string ans(n,' ');
        int maxfreq=0; 
        char ch;
        for(auto i:s)
        {
            freq[i-'a']++;
            if(freq[i-'a']> (n+1)/2)
            {
                return ""; 
            }
            if(freq[i-'a']>maxfreq)
            {
                maxfreq= freq[i-'a'];
                ch= i;
            }
        }
        int idx=0;
        while(maxfreq-- && idx<n)
        {
            ans[idx]= ch;
            idx+=2;
        }
        freq[ch-'a']= maxfreq;

        for(int i=0;i<26;i++)
        {
            while(freq[i]>0)
            {
                if(idx>=n)
                {
                    idx=1;
                }
                ans[idx]= i+'a';
                freq[i]--;
                idx+=2;
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //Max Heap..
    string reorganizeString(string s) 
    {
        vector<int>freq(26,0);
        string ans="";
        int n= s.size(); 
        for(auto i:s)
        {
            freq[i-'a']++;
            if(freq[i-'a']> (n+1)/2)
            {
                return ""; 
            }
        }
        //max heap..
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                pq.push({freq[i],i+'a'});
            }
        }
        while(pq.size()>=2)
        {
            auto top1= pq.top();
            pq.pop();
            auto top2= pq.top();
            pq.pop();
            ans+= top1.second;
            ans+= top2.second;
            if(top1.first>1)
            {
                pq.push({top1.first-1,top1.second});
            }
            if(top2.first>1)
            {
                pq.push({top2.first-1,top2.second});
            }
        }
        if(!pq.empty())
        {
            ans+= pq.top().second;
        }
        return ans;
    }
*/