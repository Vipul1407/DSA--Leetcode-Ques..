class Solution {
public:
    int countOperations(int nums1, int nums2) 
    {
        int ans=0;
        while(nums1!=0 && nums2!=0)
        {
            if(nums1>=nums2)
            {
                nums1-=nums2;
            }
            else
            {
                nums2-=nums1;
            }
            ans++;
        }
        return ans;
    }
};