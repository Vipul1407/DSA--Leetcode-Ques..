class Solution {
public:
    bool check(int i,int sum,int num,string str)
    {
        if(i==str.size())
        {
            return sum==num;
        }
        bool possi= false;
        for(int j=i;j<str.size();j++)
        {
            string sub= str.substr(i,j-i+1);
            possi= possi || check(j+1,sum+stoi(sub),num,str);
            if(possi==true)
            {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) 
    {
        int ans=0;
        for(int num=1;num<=n;num++)
        {
            int str= num*num;
            if(check(0,0,num,to_string(str)))
            {
                ans+= str;
            }
        }
        return ans;
    }
};