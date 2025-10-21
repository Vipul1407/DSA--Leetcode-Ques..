class Solution {
public:
    //METHOD-1
    //BFS..
    //TC= O(N*D)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>st(begin(wordList),end(wordList));
        if(!st.count(endWord))
        {
            return 0;
        }
        unordered_set<string>vis;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        vis.insert(beginWord);
        int ans= INT_MAX;
        while(q.size())
        {
            int n= q.size();
            while(n--)
            {
                string curr= q.front().first;
                int cnt= q.front().second;
                q.pop();
                if(curr==endWord)
                {
                    ans= min(ans,cnt);
                }
                for(int i=0;i<curr.size();i++)
                {
                    string temp= curr;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(st.count(temp) && !vis.count(temp))
                        {
                            q.push({temp,cnt+1});
                            vis.insert(temp);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX? 0:ans;
    }
};