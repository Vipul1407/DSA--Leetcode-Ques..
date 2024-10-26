class Solution {
public:
    long long minimumSteps(string s) 
    {
        //right-->left
        //trying to make 0's to left
        long long ans=0;
        int cnt0=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                cnt0++;
            }
            else
            {
                ans+=cnt0;
            }
        }
        return ans;
    }
};

//METHOD-1
// long long minimumSteps(string s) 
//     {
//         //left-->right
//          //trying to make 1's to right
//         long long ans=0;
//         int cnt1=0;
//         for(auto i:s)
//         {
//             if(i=='1')
//             {
//                 cnt1++;
//             }
//             else
//             {
//                 ans+=cnt1;
//             }
//         }
//         return ans;
//     }