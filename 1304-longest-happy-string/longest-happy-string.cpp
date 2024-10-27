class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        //max heap..
        priority_queue<pair<int,char>>pq;

        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        string ans="";
        while(pq.size())
        {
            auto top=pq.top();
            pq.pop();
            int n= ans.size();
            //cannot use curr char..
            if(n>=2 && (ans[n-1]==top.second && ans[n-2]==top.second))
            {
                if(pq.empty())
                {
                    break;
                }
                auto newtop= pq.top();
                pq.pop();
                ans+= newtop.second;
                if(newtop.first-1>0)
                {
                    pq.push({newtop.first-1,newtop.second});
                }
                //pushing prev top...
                pq.push(top);
            }
            else
            {
                ans+= top.second;
                if(top.first-1>0)
                {
                    pq.push({top.first-1, top.second});
                }
            }
        }
        return ans;
    }
};

//METHOD-1
/*
string longestDiverseString(int a, int b, int c)
{
    // max heap..
    priority_queue<pair<int, char>> pq;

    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string ans = "";
    while (pq.size())
    {
        auto top = pq.top();
        pq.pop();
        int n = ans.size();
        // can use curr char..
        if (n < 2 || (ans[n - 1] != top.second || ans[n - 2] != top.second))
        {
            ans += top.second;
            if (top.first - 1 > 0)
            {
                pq.push({top.first - 1, top.second});
            }
        }
        else
        {
            if (pq.empty())
            {
                break;
            }
            auto newtop = pq.top();
            pq.pop();
            ans += newtop.second;
            if (newtop.first - 1 > 0)
            {
                pq.push({newtop.first - 1, newtop.second});
            }
            // pushing prev top...
            pq.push(top);
        }
    }
    return ans;
}
*/