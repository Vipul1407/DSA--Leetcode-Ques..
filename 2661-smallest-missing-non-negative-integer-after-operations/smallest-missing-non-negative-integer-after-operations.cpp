class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int v) 
    {
        int n= nums.size();
	    vector<int>vec(v,0);
        for(auto i:nums)
        {
            int rem= ((i%v)+v)%v;
            vec[rem]++;
        }
        int ans=0;
        while(true)
        {
            if(vec[ans%v]==0)
            {
                return ans;
            }
            vec[ans%v]--;
            ans++;
        }
	}
};