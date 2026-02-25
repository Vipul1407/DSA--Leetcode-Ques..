class Solution {
public:
    int setbits(int n)
    {
        int cnt=0;
        while(n>0)
        {
            if(n & 1)
            {
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int>ans;
        vector<pair<int,int>>vec;
        for(auto i:arr)
        {
            vec.push_back({setbits(i),i});
        }
        sort(begin(vec),end(vec));
        for(auto i:vec)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};