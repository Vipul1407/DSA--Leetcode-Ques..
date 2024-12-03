class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        std::string newStr(n + m, ' '); // Allocate space for the result
        int i = 0, idx = 0;

        for (int spc : spaces) {
            // Copy characters from the original string until the space index
            while (i < spc) {
                newStr[idx++] = s[i++];
            }
            // Insert a space at the specified index
            newStr[idx++] = ' ';
        }

        // Copy the remaining characters of the original string
        while (i < n) {
            newStr[idx++] = s[i++];
        }

        return newStr;
    }
};