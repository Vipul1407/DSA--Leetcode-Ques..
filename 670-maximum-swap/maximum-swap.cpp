class Solution {
public:
    int maximumSwap(int num) 
    {
        string str= to_string(num);
        int n= str.size();

        vector<int>rightmax(n,0);//storing index of right max element otherwise curr element index
        rightmax[n-1]=n-1;//becoz n-1 th element has no right..

        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= str[i]>str[rightmax[i+1]]? i:rightmax[i+1];
        }
        for(int i=0;i<n;i++)
        {
            if(str[i]<str[rightmax[i]])
            {
                swap(str[i],str[rightmax[i]]);
                break;
            }
        }
        return stoi(str);
    }
};