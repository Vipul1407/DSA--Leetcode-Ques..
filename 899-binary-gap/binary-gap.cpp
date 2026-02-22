class Solution {
public:
    //METHOD-2
    int binaryGap(int n) 
    {
        int prev=-1;
        int ans=0;
        for(int i=0;i<31;i++)
        {
            if((n>>i) & 1)
            {
                if(prev!=-1)
                {
                    ans= max(ans,i-prev);
                }
                prev=i;
            } 
        }
        return ans;
    }
};
/*
    //METHOD-1
    int binaryGap(int n) 
    {
        string str="";
        for(int i=31;i>=0;i--)
        {
            str+= ((n>>i) & 1)+'0';
        }
        int prev=-1;
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(str[i]=='0')
            {
                continue;
            }
            if(prev!=-1)
            {
                ans= max(ans,i-prev);
            }
            prev=i;
        }
        return ans;
    }
*/