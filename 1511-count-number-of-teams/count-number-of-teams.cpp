// Approach 1 -> Take a middle element and find its leftSmallest and rightGreatest
// or find its leftGreatest and rightSmallest  and directly multiply these and add in ans

// TC= O(N * (2N)) ->> O[2* N^2] ->> O(N^2)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n= rating.size();
        
        int ans= 0;
        for(int i=1; i<n-1; i++)
        {
            int leftSmallest= 0;
            int leftGreatest= 0;
            
            // find leftGreatest, leftSmallest...
            for(int j= i-1; j>=0; j--)
            {
                if(rating[j] < rating[i])
                {
                    leftSmallest++;
                }
                else
                {
                    leftGreatest++;
                }
            }
          
            // find rightGreatest, rightSmallest....
            int rightSmallest= 0;
            int rightGreatest= 0;

            for(int j=i+1; j<n; j++)
            {
                if(rating[i] < rating[j])
                {
                    rightGreatest++;
                }
                else
                {
                    rightSmallest++;
                }
            }
        
        ans+= (leftSmallest* rightGreatest);
        ans+= (leftGreatest* rightSmallest);
        }
      return ans;  
    }
};