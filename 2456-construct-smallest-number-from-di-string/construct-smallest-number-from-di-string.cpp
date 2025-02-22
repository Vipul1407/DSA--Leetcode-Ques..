class Solution {
public:
    //METHOD-2
    //Using STACK..
    string smallestNumber(string pattern) 
    {
        int n= pattern.size();
        int cnt=1;
        stack<int>st;
        string ans="";
        for(int i=0;i<=n;i++)
        {
            st.push(cnt);
            cnt++;
            if(i==n || pattern[i]=='I')
            {
                while(st.size())
                {
                    ans+= st.top()+'0';
                    st.pop();
                }
            }
        }
        while(st.size())
        {
            ans+= st.top()+'0';
            st.pop();
        }
        return ans;
    }
};
/*
//METHOD-1
    //BRUTE FORCE
    //Using Next Permutation..
    bool match_pattern(string num, string &pattern)
    {
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='I' && num[i]>num[i+1])
            {
                return false;
            }
            if(pattern[i]=='D' && num[i]<num[i+1])
            {
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern) 
    {
        int n= pattern.size();
        string num="";
        for(int i=1;i<=n+1;i++)
        {
            num+= (i+'0'); 
        }
        while(!match_pattern(num,pattern))
        {
            next_permutation(num.begin(),num.end());
        }
        return num;
    }
*/