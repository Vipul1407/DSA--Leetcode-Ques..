class Solution {
public:
    int isPrefixOfWord(string str, string search) 
    {
        int n= str.size();
        int m= search.size();
        int k=0;
        int start=1;
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
};

