class Solution {
public:
    int hIndex(vector<int>& cit) 
    {
        int n= cit.size();
        int low= 0;
        int high= n-1;//starting from n-1 
        //otherwise will go out of bound
        while(low<=high)
        {
            int mid= (low+high)/2;
            //since array is sorted so it means that
            //we have n-mid papers with atleast n-mid citations so this will be our ans 
            if(cit[mid]== n-mid)
            {
                return n-mid;
            }
            else if(cit[mid] > n-mid)
            {
                high= mid-1;
            }
            else
            {
                low= mid+1;
            }
        }
        //if not find ans then return this
        return n-low;
    }
};