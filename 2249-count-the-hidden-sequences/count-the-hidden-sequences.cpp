class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) 
    {
        int n= arr.size();
        int maxval=0;
        int minval=0;
        int curr=0;
        int a=0,b=0;
        for(auto d:arr)
        {
            curr+=d;
            maxval= max(maxval,curr);
            minval= min(minval,curr);
            a= lower-minval;
            b= upper-maxval;
            if(b-a+1<=0)
            {
                return 0;
            }
        }
        return b-a+1;
    }
};