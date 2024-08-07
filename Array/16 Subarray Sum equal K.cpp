// Timme Complexity  -> O(n)
//  Space Complexity -> O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cumulativeSumFreq;
        cumulativeSumFreq[0] = 1; // base case to handle sum == k

        int cumulativeSum = 0;
        int count = 0;

        for (int num : nums) {
            cumulativeSum += num;
            // Check if there is a cumulative sum that when removed leaves the desired sum k
            if (cumulativeSumFreq.find(cumulativeSum - k) != cumulativeSumFreq.end()) {
                count += cumulativeSumFreq[cumulativeSum - k];
            }
            // Record the current cumulative sum in the map
            cumulativeSumFreq[cumulativeSum]++;
        }
        return count;
    }
};
