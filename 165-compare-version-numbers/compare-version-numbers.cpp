class Solution {
public:
    //METHOD-1
    //Using stringstream Approach
    vector<string>fun(string &v)
    {
        stringstream ss(v);
        vector<string>store;
        string token="";
        while(getline(ss,token,'.'))
        {
            store.push_back(token);
        }
        return store;
    }
    int compareVersion(string v1, string v2) 
    {
        vector<string>arr1= fun(v1);
        vector<string>arr2= fun(v2);
        int n= arr1.size();
        int m= arr2.size();
        int i=0;
        while(i<n || i<m)
        {
            int x= (i<n)? stoi(arr1[i]):0;
            int y= (i<m)? stoi(arr2[i]):0;
            if(x<y)
            {
                return -1;
            }
            else if(x>y)
            {
                return 1;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};