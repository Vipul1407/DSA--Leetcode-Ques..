class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        std::vector<std::pair<int, char>> chars = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            // Sort characters by their remaining count
            std::sort(chars.begin(), chars.end(), [](const std::pair<int, char>& p1, const std::pair<int, char>& p2) {
                return p1.first > p2.first;
            });
            
            bool added = false;
            
            // Try to add the most frequent character without violating the consecutive rule
            for (int i = 0; i < 2; ++i) {
                if (chars[i].first > 0) {
                    int len = result.length();
                    // Check if adding this character violates the consecutive rule
                    if (len >= 2 && result[len - 1] == chars[i].second && result[len - 2] == chars[i].second) {
                        continue;  // Skip if it does
                    }
                    // Add the character to the result and decrement its count
                    result += chars[i].second;
                    chars[i].first--;
                    added = true;
                    break;
                }
            }
            if (!added) {
                // If no character can be added, stop the loop
                break;
            }
        }
        
        return result;
    }
};