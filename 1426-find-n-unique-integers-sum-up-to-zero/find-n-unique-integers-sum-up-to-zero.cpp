class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int>ans;
        int start=1;
        while(n>=2)
        {
            ans.push_back(start);
            ans.push_back(-start);
            start++;
            n-=2;
        }
        if(n==1)
        {
            ans.push_back(0);
        }
        return ans;
    }
};