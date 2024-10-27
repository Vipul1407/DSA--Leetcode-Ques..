class Solution {
public:
    //METHOD-2
    //SC=O(1)
    int maximumSwap(int num) 
    {
        string str= to_string(num);
        int n= str.size();
        vector<int>vec(10,-1);//stroing index
        //left ---> right traversal
        for(int i=0;i<n;i++)
        {
            vec[str[i]-'0']=i;
        }
        for(int i=0;i<n;i++)
        {
            int digit= str[i]-'0';
            for(int j=9;j>digit;j--)
            {
                if(vec[j]>i)
                {
                    swap(str[i],str[vec[j]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};

//METHOD-1
//USING SC=O(N)
/*
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
*/