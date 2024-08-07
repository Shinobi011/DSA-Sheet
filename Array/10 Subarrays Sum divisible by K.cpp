// Time Complexity  -> O(n)
// Space Complexity -> O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;  // Initialize with 0 remainder having one count to handle the initial subarray case.
        int cumulativeSum = 0;
        int result = 0;

        for (int num : nums) {
            cumulativeSum += num;
            int remainder = cumulativeSum % k;
            
            // Adjust remainder to be positive
            if (remainder < 0) {
                remainder += k;
            }

            // Check if the remainder has been seen before
            if (remainderCount.find(remainder) != remainderCount.end()) {
                result += remainderCount[remainder];
            }

            // Increment the count for this remainder
            remainderCount[remainder]++;
        }

        return result;
    }
};
