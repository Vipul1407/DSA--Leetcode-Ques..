class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>pref(n,1);//prefix array stroing length of increasing substring..
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                pref[i]= pref[i+1]+1;
            }
        }
        
        // Step 2: Binary search to find the maximum k
        //max value that k can take is n/2 as we have to find 2 arrays..and gap b/w them must be k
        //min value of k will be 1 
        int low=1;
        int high= n/2;
        int k=0;
        while(low<=high)
        {
            bool flag= false;
            int mid= low+(high-low)/2;
            // Check if there are two adjacent increasing subarrays of length at least mid
            // ending at n-mid*2 becoz if our mid is k then we have to find 2 subarrays of length mid then if we start at a=mid-n*2 then our 1st subarray end at n-mid and 2nd will n-1
            for(int a=0;a<=n-2*mid;a++)
            {
                if(pref[a]>=mid && pref[a+mid]>=mid)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                k= mid;
                low=mid+1;//try to find large k
            }
            else
            {
                high=mid-1;//try for small k
            }
        }
        return k;
    }
};

//BRUTE FORCE..
//TC= O(N^2)
//SC= O(N)
/*
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        int n= nums.size();

        vector<int>pref(n,1);    
        for(int i=1;i<n;i++)
            {
                if(nums[i]>nums[i-1])
                {
                    pref[i]= pref[i-1]+1;
                }
            }
        int ans=0;
        for(int k=1;k<n;k++)
            {
                for(int i=k;i<n;i++)
                {
                    if(pref[i-k]>=k && pref[i]>=k)
                    {
                        ans= max(ans,k);
                    }
                }   
            }
        
        return ans;
    }
};
*/

