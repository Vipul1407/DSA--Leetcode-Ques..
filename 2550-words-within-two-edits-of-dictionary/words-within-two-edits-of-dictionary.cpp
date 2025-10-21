class Solution {
public:
    //METHOD-2
    //SIMPLE APPROACH..
    //TC= O(Q*L*26)
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        vector<string>ans;
        for(auto a:queries)
        {
            for(auto b:dictionary)
            {
                int cnt=0;
                if(a.size()!=b.size())
                {
                    continue;
                }
                int i=0, n=b.size();
                while(i<n && cnt<=2)
                {
                    if(a[i]!=b[i])
                    {
                        cnt++;
                    }
                    i++;
                }
                if(cnt<=2)
                {
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BFS..
    //TLE........
    //TC= O(Q * (26L)^2 * L)
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        unordered_set<string> st(begin(dictionary),end(dictionary));
        vector<string>ans;

        for(auto i:queries)
        {
            unordered_set<string> vis;
            queue<pair<string, int>> q;
            q.push({i, 0});
            vis.insert(i);
            int f=0;
            while (q.size() && f==0)
            {
                int n = q.size();
                while (n--)
                {
                    string curr = q.front().first;
                    int cnt = q.front().second;
                    q.pop();

                    if (st.count(curr))
                    {
                        ans.push_back(i);
                        f=1;
                        break;
                    }
                    for (int i = 0; i < curr.size(); i++)
                    {
                        string temp = curr;
                        for (char ch = 'a'; ch <= 'z'; ch++)
                        {
                            temp[i] = ch;
                            if (!vis.count(temp) && cnt<2)
                            {
                                q.push({temp, cnt + 1});
                                vis.insert(temp);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
*/