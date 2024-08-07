//Time Complexity: O(nlogn)
// Space Complexity -> (n)

class Solution {
public:
    long long findMinDiff(vector<long long>& arr, long long n, long long m) {
        // Sort the given packets
        sort(arr.begin(), arr.end());

        // Number of students cannot be more than number of packets
        if (m > n) {
            return -1;
        }

        // Find the minimum difference
        int min_diff = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        return min_diff;
    }
};