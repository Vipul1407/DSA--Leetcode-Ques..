class Solution {
public:
    int totalMoney(int n) 
    {
        int ans=0;
        int start=1;//first monday..
        int next=1;
        int a= n/7;
        int b= n%7;
        if(a==0)
        {
            while(b>0)
            {
                ans+= start;
                start++;
                b--;
            }
            return ans;
        }
        while(a>0)
        {
            for(int i=0;i<7;i++)
            {
                ans+= start;
                start++;
            }
            a--;
            next++;
            start= next;
        }
        while(b>0)
        {
            ans+= start;
            start++;
            b--;
        }
        return ans;
    }
};