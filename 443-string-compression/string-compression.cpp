class Solution {
public:
    int compress(vector<char>& arr) 
    {
        int n= arr.size();
        int i=0;//original index..
        int k=0;//updated index..
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(i<n && arr[i-1]==arr[i])
            {
                cnt++;
            }
            else
            {
                arr[k++]= arr[i-1];//if cnt==1 then we have to only add the char not count
                if(cnt>1)
                {
                    string num= to_string(cnt);
                    for(auto d:num)
                    {
                        arr[k++]= d;
                    }
                }
                cnt=1;//reinitialized to 1
            }
        }
        //handling last char..will not req now as we have handled it by <=n in for loop
        return k;//new arr size
    }
};