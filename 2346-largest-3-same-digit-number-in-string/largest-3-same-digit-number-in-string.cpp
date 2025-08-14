class Solution {
public:
    string largestGoodInteger(string num) 
    {
        string ans;
        int n= num.size();
        for(int i=1;i<n-1;i++)
        {
            if(num[i]==num[i-1] && num[i]==num[i+1])
            {
                ans= max(ans,num.substr(i-1,3));
            }
        }   
        return ans;
    }
};