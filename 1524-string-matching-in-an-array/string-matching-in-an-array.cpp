class Solution {
public:
    //METHOD-4
    //BRUTE FORCE-4
    //Finding words[i] in words[j] as substring and using break instead of unordered_set..
    vector<string> stringMatching(vector<string>& words) 
    {
        int n= words.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(words[j].find(words[i])!=string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

/*


// METHOD-2
// BRUTE FORCE2
// ABDUL BARI WAY.... OF NAIVE ALGO OF KMP(ABDUL BARI)
// TC= O(n^2 * n * m)
bool issubstring(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    // to find that is str2 substring of str1..
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        if (str1[i] == str2[j])
        {
            j++;
            if (j == m)
            {
                return true;
            }
        }
        else
        {
            if (j > 0)
            {
                i -= j;
            }
            j = 0;
        }
    }
    return false;
}
vector<string> stringMatching(vector<string> &words)
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

// METHOD-3
// BRUTE FORCE3
vector<string> stringMatching(vector<string> &words)
{
    int n = words.size();
    vector<string> ans;
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (words[i].find(words[j]) != string::npos)
            {
                st.insert(words[j]);
            }
        }
    }
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}

//METHOD-5
//KMP-->OPTIMIZED TC=O(M+N)

*/

   