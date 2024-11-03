class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        int m= goal.size();
        int n=s.size();
        if(m!=n)
        {
            return false;
        }
        string news=s+s;
        return news.find(goal)!= string::npos;
    }
};

/*
BRUTE FORCE
TC= O(N^2)
SC= O(1)
    bool rotateString(string s, string goal) 
    {
        string news= s+s;
        int m= goal.size();
        int n= s.size();
        if(m!=n)
        {
            return false;
        }
        int idx=0;
        for(int i=0;i<n;i++)
        {
           if(news.substr(i,m)==goal)
           {
                return true;
           }
        }
        return false;
    }
*/