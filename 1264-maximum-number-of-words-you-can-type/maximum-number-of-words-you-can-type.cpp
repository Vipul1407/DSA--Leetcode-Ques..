class Solution {
public:
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
        while(ss>>str)
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
};