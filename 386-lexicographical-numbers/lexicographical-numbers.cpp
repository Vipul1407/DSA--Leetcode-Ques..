class Solution {
public:
    void rec(int start,int n,vector<int>&ans)
    {
        if(start>n)
        {
            return;
        }
        ans.push_back(start);
        for(int i=0;i<=9;i++)
        {
            int num= start*10+i;
            if(num>n)
            {
                return;
            }
            rec(num,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) 
    {
        vector<int>ans;
        for(int start=1;start<=9;start++)
        {
            if(start>n)
            {
                break;
            }
            rec(start,n,ans);
        }
        return ans;
    }
};