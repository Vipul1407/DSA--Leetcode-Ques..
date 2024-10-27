class Solution {
public:
    string reorganizeString(string s) 
    {
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++)
        {
            if(vec[i]>0)
                pq.push({vec[i],i+'a'});
        }
        string ans="";
        //same logic as LONGEST HAPPY STRING QUES..
        while(pq.size())
        {
            auto top= pq.top();
            pq.pop();
            int n= ans.size();
            //can reuse same char..
            if(n==0 || ans[n-1]!=top.second)
            {
                ans+= top.second;
                if(top.first-1>0)
                {
                    pq.push({top.first-1,top.second});
                }
            }
            //cannot use same char...
            else
            {
                if(pq.empty())
                {
                    return "";
                }
                auto newtop= pq.top();
                pq.pop();
                ans+= newtop.second;
                if(newtop.first-1>0)
                {
                    pq.push({newtop.first-1, newtop.second});
                }
                pq.push(top);
            }
        }
        return pq.empty()?ans:"";
    }
};