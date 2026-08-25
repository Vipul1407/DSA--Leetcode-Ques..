class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        int no= k;
        while(true)
        {
           if(st.count(no))
           {
               no+= k;
               continue;
           }
           else
           {
               return no;
           }
        }
      return -1;  
    }
};