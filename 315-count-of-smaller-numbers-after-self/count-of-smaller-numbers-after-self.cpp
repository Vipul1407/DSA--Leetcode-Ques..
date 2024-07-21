class Solution {
public:

    void merge(vector<int>&ans, vector<pair<int,int>>&vec, int l, int mid, int r)
    {
        vector<pair<int,int>>temp(r-l+1);
        int i=l;
        int j= mid+1;
        int k=0;

        while(i<=mid && j<=r)
        {
            if(vec[i].first<= vec[j].first)
            {
                temp[k++]= vec[j++];
            }
            else
            {
                ans[vec[i].second]+= r-j+1;
                temp[k++]= vec[i++];
            }
        }

        while(i<=mid)
        {
            temp[k++]= vec[i++];
        }

        while(j<=r)
        {
            temp[k++]= vec[j++];
        }

        for(int i=l;i<=r;i++)
        {
            vec[i]= temp[i-l];
        }
    }
    void mergesort(vector<int>&ans, vector<pair<int,int>>&vec, int l, int r)
    {
        if(l<r)
        {
            int mid= l+(r-l)/2;
            mergesort(ans,vec,l,mid);
            mergesort(ans,vec,mid+1,r);
            merge(ans,vec,l,mid,r);
        }
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n= nums.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        vector<int>ans(n,0);
        mergesort(ans, vec, 0, n-1);
        return ans;
    }
};