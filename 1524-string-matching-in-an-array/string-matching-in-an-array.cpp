class Solution {
public:
    bool issubstring(string &str1, string &str2)
    {
        int n= str1.size();
        int m= str2.size();
        //to find that is str2 substring of str1..
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            if(str1[i]==str2[j])
            {
                j++;
                if(j==m)
                {
                    return true;
                }
            }
            else
            {
                if(j>0)
                {
                    i-=j;
                }
                j=0;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> vec;
        unordered_set<string> st;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string str1 = words[i];
            for (int j = 0; j < n; j++)
            {
                string str2 = words[j];
                if (i == j)
                {
                    continue;
                }
                if (issubstring(str1, str2))
                {
                    st.insert(str2);
                }
            }
        }
        for (auto i : st)
        {
            vec.push_back(i);
        }
        return vec;
    }
};