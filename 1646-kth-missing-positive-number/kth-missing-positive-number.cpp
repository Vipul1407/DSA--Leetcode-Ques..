class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n= arr.size();
        for(auto i:arr)
        {
            if(i<=k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }
};