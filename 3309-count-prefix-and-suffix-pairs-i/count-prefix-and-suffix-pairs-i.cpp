class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int n= words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int l= words[j].find(words[i]);
                int r= words[j].rfind(words[i]);
                if(l==0 && (words[j].length()-words[i].length()==r))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};