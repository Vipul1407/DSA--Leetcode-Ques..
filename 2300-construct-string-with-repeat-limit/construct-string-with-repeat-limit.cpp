class Solution {
public:
    string repeatLimitedString(string s, int k) 
    {
        priority_queue<char>pq;
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(vec[i]>0)
            {
                pq.push(i+'a');
            }
        }
        string ans;
        while(pq.size())
        {
            char ch= pq.top();
            pq.pop();
            int x= min(vec[ch-'a'],k);
            ans.append(x,ch);
            vec[ch-'a']-=x;
            if(vec[ch-'a']>0)
            {
                if(pq.empty())
                {
                    break;
                }
                char newch= pq.top();
                pq.pop();
                ans+= newch;
                vec[newch-'a']--;
                if(vec[newch-'a']>0)
                {
                    pq.push(newch);
                }
            }
            if(vec[ch-'a']>0)
            {
                pq.push(ch);
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    string repeatLimitedString(string s, int k) 
    {
        vector<int>vec(26,0);
        string ans="";
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        int i=25;
        while(i>=0)
        {
            if(vec[i]==0)
            {
                i--;
                continue;
            }
            int x= min(vec[i],k);
            //ans.append(i+'a',x);
            vec[i]-=x;
            while(x--)
            {
                ans+= i+'a';
            }
            //if still curr element cnt>0 then go to prev element add it 1 time then again come back to ith element..
            if(vec[i]>0)
            {
                int j=i-1;
                while(j>=0 && vec[j]==0)
                {
                    j--;
                }
                if(j<0)
                {
                    break;
                }
                //only add 1 time..
                if(vec[j]>0)
                {
                    ans+= j+'a';
                    vec[j]--;
                }
            }
        }
        return ans;
    }
};
*/