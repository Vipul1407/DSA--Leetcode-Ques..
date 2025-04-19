class Solution {
public:
    // METHOD-2
    // TC= O(N)
    string reorganizeString(string s)
    {
        int n = s.size();
        vector<int> vec(26, 0);
        string ans(n,' ');
        int maxfreq=0;
        char ch;
        for (auto i : s)
        {
            vec[i - 'a']++;
            if (vec[i - 'a'] > (n + 1) / 2)
            {
                return "";
            }
            if(vec[i-'a']>maxfreq)
            {
                ch= i;
                maxfreq= vec[i-'a'];
            }
        }
        int i=0;
        int cnt= vec[ch-'a'];
        while(i<n && cnt>0)
        {
            ans[i]= ch;
            cnt--;
            i+=2;
        }
        vec[ch-'a']= 0;
        for(char ch='a';ch<='z';ch++)
        {
            while(vec[ch-'a']>0)
            {
                if(i>=n)
                {
                    i=1;
                }
                ans[i]= ch;
                vec[ch-'a']--;
                i+=2;
            }
        }
        return ans;
    }
};
/*
    // METHOD-1
    // PRIORITY_QUEUE
    // TC= O(NLOGN)
    string reorganizeString(string s)
    {
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        vector<int> vec(26, 0);
        for (auto i : s)
        {
            vec[i - 'a']++;
            if (vec[i - 'a'] > (n + 1) / 2)
            {
                return "";
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (vec[i] > 0)
                pq.push({vec[i], i + 'a'});
        }
        string ans = "";
        while (pq.size() >= 2)
        {
            auto ele1 = pq.top();
            pq.pop();
            auto ele2 = pq.top();
            pq.pop();
            ans += ele1.second;
            ans += ele2.second;
            if (ele1.first > 1)
            {
                pq.push({ele1.first - 1, ele1.second});
            }
            if (ele2.first > 1)
            {
                pq.push({ele2.first - 1, ele2.second});
            }
        }
        if (!pq.empty())
        {
            ans += pq.top().second;
        }
        return ans;
    }
*/