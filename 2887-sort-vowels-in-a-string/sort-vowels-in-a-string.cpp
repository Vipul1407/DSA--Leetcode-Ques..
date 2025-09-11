class Solution {
public:
    //METHOD-2
    //TC= O(N) Without Using Sorting..
    string sortVowels(string s) 
    {
        vector<char>vow;
        int n= s.size();
        unordered_map<char,int>freq;
        for(auto i:s)
        {
            freq[i]++;
        }
        string order= "AEIOUaeiou";
        int idx=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                while(freq[order[idx]]==0 && idx<order.size())
                {
                    idx++;
                }
                s[i]= order[idx];
                freq[order[idx]]--;
            }
        }
        return s;
    }
};
/*
    //METHOD-1
    //TC= O(NLOGN) Using Sorting..
    string sortVowels(string s) 
    {
        vector<char>vow;
        int n= s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                vow.push_back(s[i]);
            }
        }
        sort(rbegin(vow),rend(vow));

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                if(vow.empty())
                {
                    break;
                }
                s[i]= vow.back();
                vow.pop_back();
            }
        }
        return s;
    }
*/