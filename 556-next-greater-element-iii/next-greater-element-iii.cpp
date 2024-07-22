class Solution {
public:
    int nextGreaterElement(int num) 
    {
        string str= to_string(num);
        string ans="";
        int n= str.length();
        int idx=-1;
        //find index of greater element from right
        for(int i=n-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            {
                idx=i;
                break;
            }
        }
        //if no element found means it means larger no. cannot be formed, it is already larger
        if(idx==-1)
        {
            return -1;
        }
        //finding just greater element than the element at idx
        int nextgreat= idx+1;
        int k= n-1;
        while(k>idx)
        {
            if(str[k]>str[idx])
            {
                nextgreat= k;
                break;
            }
            k--;
        }
        //swap both elements
        swap(str[idx],str[nextgreat]);

        //after swapping sort the remainging right side string
        sort(str.begin()+idx+1, str.end());

        //converting back string to long long
        long long res= stoll(str);

        //if ans fits in 32-bit integer then return it else return -1
        return res<=INT_MAX? res: -1;
    }
};
