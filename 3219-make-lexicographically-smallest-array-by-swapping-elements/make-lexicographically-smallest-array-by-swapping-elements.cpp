
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Copy nums and sort it.
        // We use this to find connected groups.
        vector<int> Groups = nums;
        sort(Groups.begin(), Groups.end());

        // Stores all sorted values belonging to each group.
        unordered_map<int, vector<int>> Group;

        // Stores which group a particular value belongs to.
        unordered_map<int, int> Belong;

        // Points to the smallest unused value in each group.
        unordered_map<int, int> Minindex;

        int id = 1;

        // First value belongs to the first group.
        Group[id].push_back(Groups[0]);

        // Create groups.
        // If consecutive sorted values differ by more than limit,
        // they cannot belong to the same connected component.
        for (int i = 1; i < n; i++) {
            if (Groups[i] - Groups[i - 1] > limit) {
                id++;
            }

            Group[id].push_back(Groups[i]);
        }

        // Find the group ID for every value.
        id = 1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && Groups[i] - Groups[i - 1] > limit) {
                id++;
            }

            Belong[Groups[i]] = id;
        }

        // Initially, no value from any group has been used.
        for (int i = 1; i <= id; i++) {
            Minindex[i] = 0;
        }

        // Traverse the original array from left to right.
        // At every position, place the smallest unused value
        // from the same group to make the array lexicographically smallest.
        for (int i = 0; i < n; i++) {
            int groupId = Belong[nums[i]];

            // Take the smallest unused value from this group.
            nums[i] = Group[groupId][Minindex[groupId]];

            // Move pointer to the next available value.
            Minindex[groupId]++;
        }

        return nums;
    }
};