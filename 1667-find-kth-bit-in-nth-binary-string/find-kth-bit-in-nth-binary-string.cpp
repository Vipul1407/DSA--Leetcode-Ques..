class Solution {
public:
    char findKthBit(int n, int k) 
    {
        if(n==1)
        {
            return '0';//s1='0'
        }
        int len= (1<<n)-1;//pow(2,n)-1;
        if(k<=len/2)
        {
            return findKthBit(n-1,k);
        }
        else if(k== (len/2)+1)
        {
            return '1';
        }
        else
        {
            char ch= findKthBit(n-1,len-(k-1));//handle the reversed bit==> we want distance of bit from last. that bit from first inverted will be our final bit.
            return ch=='0'? '1':'0';//flipp the bit..
        }
    }
};