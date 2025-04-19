class Solution {
public:
    //TC= O(NLOGN)
    string reorganizeString(string s) 
    {
        int n= s.size();
        priority_queue<pair<int,char>>pq;
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
            if(vec[i-'a'] > (n+1)/2)
            {
                return "";
            }
        }
        for(int i=0;i<26;i++)
        {
            if(vec[i]>0)
                pq.push({vec[i],i+'a'});
        }
        string ans="";
        while(pq.size()>=2)
        {
            auto ele1= pq.top();
            pq.pop();
            auto ele2= pq.top();
            pq.pop();
            ans+= ele1.second;
            ans+= ele2.second;
            if(ele1.first>1)
            {
                pq.push({ele1.first-1,ele1.second});
            }
            if(ele2.first>1)
            {
                pq.push({ele2.first-1,ele2.second});
            }
        }
        if(!pq.empty())
        {
            ans+= pq.top().second;
        }
        return ans;
    }
};