class Solution {
public:
    //USING Stringstream + Getine function..
    int isPrefixOfWord(string str, string search) 
    {
        stringstream ss(str);
        int start=1;
        string word;
        while(getline(ss,word,' '))
        {
            if(word.find(search)==0)
            {
                return start;
            }
            start++;
        }
        return -1;
    }
};

/*
//METHOD-2
//BEATS 100%
// Using stringstream
int isPrefixOfWord(string str, string search)
{
    stringstream ss(str);
    int start = 1;
    string word;
    while (ss >> word)
    {
        if (word.find(search) == 0)
        {
            return start;
        }
        start++;
    }
    return -1;
}

//METHOD-1
// BEATS 100%
int isPrefixOfWord(string str, string search) 
{
    int n= str.size();
    int m= search.size();
    int k=0;
    int start=1;//to track word index in sentence..
    bool neww= true;
    for(int i=0;i<n;i++)
    {
        if(str[i]==' ')
        {
            k=0;
            neww= true;
            start++;
        }
        else if(neww)
        {
            if(str[i]==search[k])
            {
                k++;
                if(k>=m)
                {
                    return start;
                }
            }
            else
            {
                k=0;
                neww= false;
            }
        }
    }
    return -1;
}
*/