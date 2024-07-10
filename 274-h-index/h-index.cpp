class Solution {
public:
    int hIndex(vector<int>& cit) 
    {
        sort(cit.begin(),cit.end());
        int i=0;
        int n=cit.size();
        while(i<n && cit[i]<n-i)
        {
            i++;
        }
        return n-i;
    }
};

//METHOD-2
//OPTIMIZED USING BINARY SEARCH
//class Solution {
// public:
//     bool possible(vector<int>& cit, int k)
//     {
//         int cnt=0;
//         for(auto i:cit)
//         {
//             if(i>=k)
//             {
//                 cnt++;
//             }
//         }
//         return cnt>=k;
//     }
//     int hIndex(vector<int>& cit) 
//     {
//        int low= 0;
//        int high= cit.size();
//        int ans=0;
//        while(low<=high)
//         {
//             int mid= (low+high)/2;
//             if(possible(cit,mid))
//             {
//                 ans= mid;
//                 low= mid+1;
//             }
//             else
//             {
//                 high= mid-1;
//             }
//         } 
//         return ans;
//     }
// };