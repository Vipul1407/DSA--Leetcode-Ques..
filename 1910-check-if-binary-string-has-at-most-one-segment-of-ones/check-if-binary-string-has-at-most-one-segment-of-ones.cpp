class Solution {
public:
    bool checkOnesSegment(string str) {
        int n= str.length();

        for(int i=1; i<n; i++)
        {
            if(str[i-1]== '0' && str[i]== '1') return false;
        }
       return true; 
    }
};