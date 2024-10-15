class Solution {
public:
    long long minimumSteps(string s) {
        
        int i = 0;
        int j = s.size()-1;

        long long int ans = 0;

        while(i < j) {

            if(s[i] == '1' && s[j] == '0') {
                swap(s[i], s[j]);
                ans += (j - i);
                i++;
                j--;
            }

            else if(s[i] == '0') {
                i++;
            }

            else if(s[j] == '1') {
                j--;
            }
        }

        return ans;
    }
};