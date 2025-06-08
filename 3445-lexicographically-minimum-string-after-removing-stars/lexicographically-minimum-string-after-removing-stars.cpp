class Solution {
public:
    //METHOD-1
    //Prioirty_queue
    string clearStars(string s) 
    {
        int n= s.size();
        //we want small element with greater index, so pushing index with -ve sign..
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                if(pq.size())
                {
                    auto top= pq.top();
                    s[-top.second]= '*';
                    pq.pop();
                }
            }
            else
            {
                pq.push({s[i],-i});
            }
        }
        string ans="";
        for(auto i:s)
        {
            if(i!='*')
            {
                ans+=i;
            }
        }
        return ans;
    }
};