class Solution {
public:
    //METHOD-2
    //Without using stringstream..
    int canBeTypedWords(string text, string brokenLetters) 
    {
        vector<int>broken(26,0);
        for(auto i:brokenLetters)
        {
            broken[i-'a']=1;
        }
        string str="";
        int cnt=0;
        int n= text.size();
        int i=0;
        while(i<n)
        {
            if(text[i]==' ')
            {
                int flag=0;
                for(auto i:str)
                {
                    if(broken[i-'a']==1 && flag==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    cnt++;
                }
                str="";//reset str..
            }
            else
            {
                str+= text[i];
            }
            i++;
        }
        //same thing must be done after loop also..
        int flag=0;
        for(auto i:str)
        {
            if(broken[i-'a']==1 && flag==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cnt++;
        }
        return cnt;
    }
};
/*
    //METHOD-1
    //Using Stringstream..
    int canBeTypedWords(string text, string brokenLetters) 
    {
        stringstream ss(text);
        vector<int>broken(26,0);
        for(auto i:brokenLetters)
        {
            broken[i-'a']=1;
        }
        string str;
        int cnt=0;
        //while(ss>>str)
        while(getline(ss,str,' '))
        {
            int flag=0;
            for(auto i:str)
            {
                if(broken[i-'a']==1 && flag==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
*/