class Solution {
public:
    //METHOD-2
    //Making pref arr of end valid range
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int n= nums.size();
        vector<int>pref(n,n-1);//to get pref[n-1]=n-1
        int j=0;
        for(int i=0;i<n-1;i++)
        {
            //getting a valid ending index range for index i
            if(j<i)
            {
                j=i;
            }
            while(j+1<n && nums[j]%2 != nums[j+1]%2)
            {
                j++;
            }
            pref[i]= j;
        }
        //pref is storing ending valid rnage for starting index i
        //pref[2]=5 means start=2 valid range is upto 5
        vector<bool>res;
        for(auto i:quer)
        {
            //i[1]= ending range of query
            //i[0]= start of quer
            //if this comes under our stored range i.e <= (ending valid range..)pref[start]
            if(i[1]<=pref[i[0]])
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    //METHOD-1
    //Making pref arr of 0 and 1
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int n= nums.size();
        vector<int>pref(n,0);
    
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2 == nums[i-1]%2)
            {
                pref[i]=pref[i-1]+1;
            }
            else
            {
                pref[i]=pref[i-1];
            }
        }
        vector<bool>res;
        for(auto i:quer)
        {
            if(pref[i[1]]-pref[i[0]]==0)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;    
    }
};
*/