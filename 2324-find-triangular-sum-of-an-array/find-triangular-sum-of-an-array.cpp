class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>vec= nums;
        while(n>1)
        {
            int i=0;
            vector<int>newvec;
            --n;
            if(n==0)
            {
                vec.push_back(vec[0]%10);
            }
            else
            {
                while(i<n)
                {
                    newvec.push_back((vec[i]+vec[i+1])%10);
                    i++;
                }
            }
            vec= newvec;
        }
        return vec[0];
    }
};