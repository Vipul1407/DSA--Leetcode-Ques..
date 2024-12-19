class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        //since all elements are unique hence we can apply prefix sum method otherwise we have to use a hash function..
        vector<int>sorted= arr;
        sort(sorted.begin(),sorted.end());
        int p=0;
        int np=0;
        int ans=0;
        int n= arr.size();
        for(int i=0;i<n;i++)
        {
            p+= arr[i];
            np+= sorted[i];
            if(p==np)
            {
                ans++;
            }
        }
        return ans;
    }
};