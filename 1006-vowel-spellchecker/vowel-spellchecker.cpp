class Solution {
public:
    bool isvowel(char ch)
    {
        ch= tolower(ch);
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        unordered_set<string>mp(begin(wordlist),end(wordlist));
        unordered_map<string,string>lowercase;
        for(auto i:wordlist)
        {
            string str= i;
            for(auto &j:str)
            {
                j= tolower(j);
            }
            if(lowercase.find(str)==lowercase.end())
            {
                lowercase[str]=i;
            }
        }
        unordered_map<string,string>vowelcase;
        for(auto i:wordlist)
        {

            string str= i;
            for(auto &j:str)
            {
                j= tolower(j);
            }
            for(auto &j:str)
            {
                if(isvowel(j))
                {
                    j='*';
                }
            }
            if(vowelcase.find(str)==vowelcase.end())
            {
                vowelcase[str]=i;
            }
        }
        vector<string>ans;
        for(auto i: queries)
        {
            if(mp.find(i)!=mp.end())
            {
                ans.push_back(i);
            }
            else
            {
                string str=i;
                for(auto &j:str)
                {
                    j= tolower(j);
                }
                if(lowercase.count(str))
                {
                    ans.push_back(lowercase[str]);
                }
                else
                {
                    str=i;
                    for(auto &j:str)
                    {
                        j= tolower(j);
                    }
                    for(auto &j:str)
                    {
                        if(isvowel(j))
                        {
                            j= '*';
                        }
                    }
                    if(vowelcase.count(str))
                    {
                        ans.push_back(vowelcase[str]);
                    }
                    else
                    {
                        ans.push_back("");
                    }
                }
            }
        }
        return ans;
    }
};