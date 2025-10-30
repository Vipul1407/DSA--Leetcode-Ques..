class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0;
        int prev = 0;

        for(int num : target){
            if(num > prev){
                res += num - prev;
            }
            prev = num;
        }
        return res;
    }
};