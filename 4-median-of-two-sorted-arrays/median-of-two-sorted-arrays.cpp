class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) 
    {
        int n= a.size();
        int m= b.size();
        if(n>m)
        {
            return findMedianSortedArrays(b,a);
        }
        //n1 wla chota h n2 se
        int low=0;
        int high= n;
        int left= (n+m+1)/2;
        
        while(low<=high)
        {
            int mid1= (low+high)/2;
            int mid2= left-mid1;
           
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            
            if(mid1<n)
            {
                r1= a[mid1];
            }
            if(mid2<m)
            {
                r2= b[mid2];
            }
            if(mid1-1>=0)
            {
                l1= a[mid1-1];
            }
            if(mid2-1>=0)
            {
                l2= b[mid2-1];
            }

            if(l1<=r2 && l2<=r1)
            {
                //odd
                if((n+m)%2==1)
                {
                    return max(l1,l2);
                }
                //even
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            //running binary search for mid1
            else if(l1>r2)
            {
                high= mid1-1;
            }
            else
            {
                low= mid1+1;
            }
        }
        return 0.00;
    }
};