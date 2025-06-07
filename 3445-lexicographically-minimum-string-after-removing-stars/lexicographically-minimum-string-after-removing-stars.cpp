class Solution {
public:
    string clearStars(string s) 
    {
        int n=s.length();
        //give in ascending order of char,then if same then it give min index but we need max index so we will push it by -i
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                if(!pq.empty())
                    pq.pop();
            }
            else
            {
                pq.push({s[i],-i});
            }
        }
        unordered_set<int>st;
        while(!pq.empty())
        {
            st.insert(-pq.top().second);
            pq.pop();
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(st.find(i)!=st.end())
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};