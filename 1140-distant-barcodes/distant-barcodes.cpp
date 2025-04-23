class Solution {
public:
    //METHOD-3
    //TC=O(N)
    //Without using heap..
    vector<int> rearrangeBarcodes(vector<int>& barcode) 
    {
        int n= barcode.size();
        vector<int>mp(10001,0);
        int ch=1;
        vector<int>ans(n,0);
        int maxfreq=1;
        for(auto i:barcode)
        {
            mp[i]++;
            //not possible case..
            // if(mp[i]>(n+1)/2)
            // {
            //     return {};
            // }
            if(mp[i]>maxfreq)
            {
                maxfreq= mp[i];
                ch= i;
            }
        }
        int j=0;
        while(j<n && maxfreq--)
        {
            ans[j]= ch;
            j+=2;
        }
        mp[ch]=0;
        for(int i=1;i<=10000;i++)
        {
            if(mp[i]>0)
            {
                while(mp[i]--)
                {
                    if(j>=n)
                    {
                        j=1;
                    }
                    ans[j]= i;
                    j+=2;
                }
            }
        }
        return ans;
    }
}; 
/*
    //METHOD-1
    //USING PRIORITY QUEUE..
    //TC= O(NLOGN)
    vector<int> rearrangeBarcodes(vector<int>& barcode) 
    {
        int n= barcode.size();
        vector<int>ans;
        //max heap.. storing freq, number 
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto i:barcode)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(pq.size()>=2)
        {
            auto ele1= pq.top();
            pq.pop();
            auto ele2= pq.top();
            pq.pop();
            ans.push_back(ele1.second);
            ans.push_back(ele2.second);
            --ele1.first;
            --ele2.first;

            if(ele1.first>0)
            {
                pq.push(ele1);
            }
            if(ele2.first>0)
            {
                pq.push(ele2);
            }
        }
        if(!pq.empty())
        {
            ans.push_back(pq.top().second);
        }
        return ans;
    }

        //METHOD-2
    //TC=O(N)
    //Without using heap..
    vector<int> rearrangeBarcodes(vector<int>& barcode) 
    {
        int n= barcode.size();
        unordered_map<int,int>mp;
        int maxfreq=1;
        int ch=1;
        for(auto i:barcode)
        {
            mp[i]++;
            //not possible case..
            // if(mp[i]> (n+1)/2)
            // {
            //     return {};
            // }
            if(mp[i]> maxfreq)
            {
                maxfreq= mp[i];
                ch= i;
            }
        }
        vector<int>ans(n,0);
        int j=0;
        while(j<n && maxfreq--)
        {
            ans[j]= ch;
            j+=2;
        }
        mp[ch]=0;

        for(auto &i:mp)
        {
            while(i.second--)
            {
                if(j>=n)
                {
                    j=1;
                }
                ans[j]= i.first;
                j+=2;
            }
        }
        return ans;
    }
*/