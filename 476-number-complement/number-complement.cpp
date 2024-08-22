class Solution {
public:

    int findComplement(int num) 
    {
        int totalbits= log2(num)+1;
        for(int i=0;i<totalbits;i++)
        {
            num= (num^(1<<i));
        }
        return num;
    }
};