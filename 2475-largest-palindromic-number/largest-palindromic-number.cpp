class Solution {
public:
    string largestPalindromic(string num) 
    {
        vector<int>vec(10,0);
        for(auto i:num)
        {
            vec[i-'0']++;
        }
        string left="";
        string right="";
        int flag=0;
        for(int i=9;i>=0;i--)
        {
            if(i==0 && flag==0)
            {
                continue;
            }
            if(vec[i]>1)
            {
                int pair= vec[i]/2;
                int rem= vec[i]%2;
                while(pair--)
                {
                    char d= i+'0';
                    left+= d;
                    right+= d;
                }
                vec[i]= rem;
                flag=1;
            }
        }
        for(int i=9;i>=0;i--)
        {
            if(vec[i]==1)
            {
                left+= i+'0';
                break;
            }
        }
        if(left+right=="")
        {
            return vec[0]>0? "0":"";
        }
        reverse(begin(right),end(right));
        return left+right;
    }
};