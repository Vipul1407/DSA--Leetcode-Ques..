class Solution {
public:
    int countOdds(int low, int high) 
    {
        
        //both even..
        if(low%2==0 && high%2==0)
        {
            return (high-low)/2;
        }
        //if 1 odd.. or //both odd...
        else 
        {
            return 1+(high-low)/2;
        }
    }
};