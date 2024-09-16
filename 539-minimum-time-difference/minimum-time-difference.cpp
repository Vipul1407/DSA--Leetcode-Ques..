class Solution {
public:

    int findMinDifference(std::vector<std::string>& timePoints) {
        int n = timePoints.size();
        std::vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            int hours = std::stoi(timePoints[i].substr(0, 2));
            int minutes = std::stoi(timePoints[i].substr(3, 2));
            times[i] = hours * 60 + minutes;
        }
        
        std::sort(times.begin(), times.end());
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n - 1; ++i) {
            minDiff = std::min(minDiff, times[i + 1] - times[i]);
        }
        
        minDiff = std::min(minDiff, 1440 + times[0] - times[n - 1]);
        
        return minDiff;
    }
};