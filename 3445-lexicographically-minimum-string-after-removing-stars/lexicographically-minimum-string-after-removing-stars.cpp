class Solution {
public:
    //METHOD-2
    //Prioirty_queue using lambda function..
    string clearStars(string s) 
    {
        int n= s.size();
        //lambda fun..
        auto cmp=[](const pair<int,int>&a, const pair<int,int>&b)
        {
            if(a.first==b.first)
            {
                return a.second<b.second;
            }
            return a.first>b.first;
        };
        //we want small element with greater index, so pushing index with -ve sign..
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                if(pq.size())
                {
                    auto top= pq.top();
                    s[top.second]= '*';
                    pq.pop();
                }
            }
            else
            {
                pq.push({s[i],i});
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
/*
    // NEW APPROACH BETTER------------------------->

// METHOD-1
// Prioirty_queue
string clearStars(string s)
{
    int n = s.size();
    // we want small element with greater index, so pushing index with -ve sign..
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            if (pq.size())
            {
                auto top = pq.top();
                s[-top.second] = '*';
                pq.pop();
            }
        }
        else
        {
            pq.push({s[i], -i});
        }
    }
    string ans = "";
    for (auto i : s)
    {
        if (i != '*')
        {
            ans += i;
        }
    }
    return ans;
}

    // OLD APPROACH------------------------------>
//  BEATS 66%
string clearStars(string s)
{
    int n = s.length();
    // to store idx of char
    vector<vector<int>> mp(26);
    vector<int> remove(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            for (auto ch = 'a'; ch <= 'z'; ch++)
            {
                if (mp[ch - 'a'].size() != 0)
                {
                    remove[mp[ch - 'a'].back()] = 1;
                    mp[ch - 'a'].pop_back();
                    break;
                }
            }
        }
        else
        {
            mp[s[i] - 'a'].push_back(i);
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (!remove[i] && s[i] != '*')
        {
            ans += s[i];
        }
    }
    return ans;
}

// PRIORITY QUEUE
string clearStars(string s)
{
    int n = s.length();
    // give in ascending order of char,then if same then it give min index but we need max index so we will push it by -i
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            if (!pq.empty())
                pq.pop();
        }
        else
        {
            pq.push({s[i], -i});
        }
    }
    unordered_set<int> st;
    while (!pq.empty())
    {
        st.insert(-pq.top().second);
        pq.pop();
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (st.find(i) != st.end())
        {
            ans += s[i];
        }
    }
    return ans;
}

*/