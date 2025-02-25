class Solution {
public:
    //METHOD-3
    //OPTIMIZED TAKING VECTOR..
    #define MOD 1000000007
    int numOfSubarrays(vector<int>& arr) 
    {
        int n= arr.size();
        long long ans=0;
        vector<int>pref(n,0);
        pref[0]= arr[0];
        for(int i=1;i<n;i++)
        {
            pref[i]= pref[i-1]+arr[i];
        }    
        //odd+even = odd
        //even+odd= odd
        //only odd--> to tackle this case we start even=1 initailly
        //Then we iterate on pref vector and if , it is odd then we add even and if it is even then we cnt oddcnt
        int odd=0;
        int even=1;
        for(int i=0;i<n;i++)
        {
            if(pref[i]%2==0)
            {
                ans+= odd;
                even++;
            }
            else
            {
                ans+= even;
                odd++;
            }
        }
        return ans%MOD;
    }
};
/*
//METHOD-1
    //BRUTE FORCE
    int numOfSubarrays(vector<int>& arr) 
    {
        int n= arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+= arr[k];
                }
                ans+= sum%2;
            }
        }    
        return ans;
    }

//METHOD-2
    //BRUTE FORCE OPTIMIZED
    int numOfSubarrays(vector<int>& arr) 
    {
        int n= arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+= arr[j];
                ans+= sum%2;
            }
        }    
        return ans;
    }
*/