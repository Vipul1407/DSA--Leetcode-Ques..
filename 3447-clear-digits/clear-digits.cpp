class Solution {
public:
    //METHOD-4
    //USING INPLACE REPLACEMENT..
    //2 POINTERS..
    string clearDigits(string s) 
    {
        int n= s.size();
        int i=0;
        int j=0;
        while(i<n)
        {
            if(isdigit(s[i]))
            {
                if(j>0)
                {
                    j--;
                }
            }
            else
            {
                s[j]=s[i];
                j++;
            }
            i++;
        }
        return s.substr(0,j);
    }
};

/*
    //METHOD-1
    //BRUTE FORCE..
    string clearDigits(string s) 
    {
        int n= s.size();
        vector<int>remove(n,0);
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                remove[i]=1;
                for(int j=i-1;j>=0;j--)
                {
                    if(remove[j]==1)
                    {
                        continue;
                    }
                    if(!isdigit(s[j]))
                    {
                        remove[j]=1;
                        break;
                    }
                }
            }
        }    
        string str="";
        for(int i=0;i<n;i++)
        {
            if(remove[i]==0)
            {
                str+= s[i];
            }
        }
        return str;
    }
    
    //METHOD-2
    //USING STACK..
    string clearDigits(string s) 
    {
        stack<char>st;
        for(auto i:s)
        {
            if(isdigit(i))
            {
                while(st.size())
                {
                    st.pop();
                    break;
                }
            }
            else
            {
                st.push(i);
            }
        }
        string ans="";
        while(st.size())
        {
            ans= st.top()+ans;
            st.pop();
        }
        return ans;
    }

    //METHOD-3
    //WITHOUT STACK..
    string clearDigits(string s) 
    {
        int n= s.size();
        string str;
        for(auto i:s)
        {
            if(isdigit(i))
            {
                while(str.size())
                {
                    str.pop_back();
                    break;
                }
            }
            else
            {
                str.push_back(i);
            }
        }
        return str;
    }
*/