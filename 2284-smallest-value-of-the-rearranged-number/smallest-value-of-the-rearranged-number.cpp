class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if(num==0)
        {
            return 0;
        }
        //if + then sort in min form and if 0 present then place it and 2nd place
        //if - then only thing is sort in max form
        string str= to_string(num);
        char pos='?';
        if(!isdigit(str[0]))
        {
            if(str[0]=='-')
            {
                pos='-';//to denote it is negative
            }
        }
        vector<char>vec;
        string ans="";
        //if it is +ve number
        if(pos=='?' || pos=='+')
        {
            for(auto i:str)
            {
                if(isdigit(i))
                {
                    vec.push_back(i);
                }
            }
            sort(vec.begin(),vec.end());
            if(pos=='+')
            {
                ans+='+';
            }
            int cnt=0;
            for(auto i:vec)
            {
                if(i=='0' && (ans=="" || ans=="+"))
                {
                    cnt++;
                    continue;
                }
                ans+=i;
                while(cnt>0 && (ans!="" || ans!="+"))
                {
                    ans+='0';
                    cnt--;
                }
            }
        }
        //is it is -ve number
        else
        {
            for(auto i:str)
            {
                if(isdigit(i))
                {
                    vec.push_back(i);
                }
            }
            sort(vec.rbegin(),vec.rend());
            ans+='-';
            for(auto i:vec)
            {
                ans+= i;
            }
        }
        return stoll(ans);
    }
};