class Solution {
public:
    int nextGreaterElement(int num) 
    {
        string str= to_string(num);
        string ans="";
        int n= str.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                idx=i;
                for(int k=n-1;k>idx;k--)
                {
                    if(str[k]> str[idx])
                    {
                        swap(str[idx],str[k]);
                        break;
                    }
                }
                break;
            }
        }
        if(idx==-1)
        {
            return -1;
        }
        reverse(str.begin()+idx+1,str.end());
        long long res= stoll(str);
        return res<=INT_MAX? res:-1;
    }
};