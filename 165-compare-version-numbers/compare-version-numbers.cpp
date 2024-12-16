class Solution {
public:
    int compareVersion(string v1, string v2) 
    {
        int n= v1.size();
        int m= v2.size();
        int i=0;
        int j=0;
        int a=0;
        int b=0;
        while(i<n || j<m)
        {
            while(i<n && v1[i]!='.')
            {
                a= a*10+(v1[i++]-'0');
            }
            while(j<m && v2[j]!='.')
            {
                b=b*10+(v2[j++]-'0');
            }
            if(a>b)
            {
                return 1;
            }
            else if(a<b)
            {
                return -1;
            }
            //for next iteration i.e after '.'
            i++;
            j++;
            a=0;
            b=0;
        }
        return 0;
    }
};
/*
//METHOD-2
// Using String Stream + Getline
// BEATS 100%
class Solution {
public:
    int compareVersion(string v1, string v2) 
    {
        stringstream ss1(v1);
        stringstream ss2(v2);
        string word;
        vector<int>a;
        vector<int>b;
        while(getline(ss1,word,'.'))
        {
            a.push_back(stoi(word));
        }
        while(getline(ss2,word,'.'))
        {
            b.push_back(stoi(word));
        }
        int n= max(a.size(),b.size());
        int i=0;
        int j=0;
        while(i<n || j<n)
        {
            int op1= i<a.size()? a[i]:0;
            int op2= j<b.size()? b[j]:0;
            if(op1==op2)
            {
                i++;
                j++;
                continue;
            }
            else if(op1>op2)
            {
                return 1;
            }
            else if(op1<op2)
            {
                return -1;
            }
        }
        return 0;
    }
};
*/