class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int>st(arr.begin(),arr.end());
        int cnt0=0;
        for(auto i:arr)
        {
            if(i==0)
            {
                cnt0++;
            }
            else
            {
                if(st.find(2*i)!=st.end())
                {
                    return true;
                }
            }
        }
        return cnt0>1 ? true:false;
    }
};