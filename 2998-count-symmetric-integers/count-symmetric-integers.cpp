class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
    //TC= O(high*d)
    int countSymmetricIntegers(int low, int high) 
    {
        int cnt=0;
        for(int i=low;i<=high;i++)
        {
            if(i>=11 && i<=99 && i%11==0)
            {
                cnt++;
            } 
            else if(i>=1000 && i<=9999)  
            {
                int first= i/1000;
                int second= (i/100)%10;
                int third= (i/10)%10;
                int fourth= i%10;
                if(first+second == third+fourth)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(high*d)
    int countSymmetricIntegers(int low, int high) 
    {
        int cnt=0;
        for(int i=low;i<=high;i++)
        {
            string s= to_string(i);
            int len= s.size();
            if(len%2==1)
            {
                continue;
            }
            int a=0,b=0;
            for(int j=0;j<len/2;j++)
            {
                a+= s[j]-'0';
            }
            for(int j=len/2;j<len;j++)
            {
                b+= s[j]-'0';
            }
            if(a==b)
            {
                cnt++;
            }
        }
        return cnt;
    }
*/