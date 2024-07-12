class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        vector<char>v,v1;
        int ans=0;
        int f;
        if(x>y)
        {
            f=1;
        }
        else
        {
            f=0;
        }
        for(auto c:s)
        {
            if(!v.empty())
            {
                if(f)
                {
                    if(v.back()=='a' && c=='b')
                    {
                        ans+=x;
                        v.pop_back();
                    }
                    else
                    {
                        v.push_back(c);
                    }
                }
                else
                {
                    if(v.back()=='b' && c=='a')
                    {
                        ans+=y;
                        v.pop_back();
                    }
                    else
                    {
                        v.push_back(c);
                    }
                }
            }
            else
            {
                v.push_back(c);
            }
        }

        for(auto c:v)
        {
            if(!v1.empty())
            {
                if(!f)
                {
                    if(v1.back()=='a' && c=='b')
                    {
                        ans+=x;
                        v1.pop_back();
                    }
                    else
                    {
                        v1.push_back(c);
                    }
                }
                else
                {
                    if(v1.back()=='b' && c=='a')
                    {
                        ans+=y;
                        v1.pop_back();
                    }
                    else
                    {
                        v1.push_back(c);
                    }
                }
            }
            else
            {
                v1.push_back(c);
            }
        }
        return ans;
    }
};