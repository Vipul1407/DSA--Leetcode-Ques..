class Solution {
public:

    int findComplement(int num) 
    {
        int totalbits= log2(num)+1;
        unsigned mask= (1U<<totalbits)-1;
        return num^mask;
    }
};