class Solution {
public:
    vector<int> divisibilityArray(string word, int p) 
    {
        long long num=0;
        int n= word.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            num= (num*10 + (word[i]-'0'))%p;
            if(num==0)
            {
                ans[i]=1;
            }
            else
            {
                ans[i]=0;
            }
        }
        return ans;
    }
};