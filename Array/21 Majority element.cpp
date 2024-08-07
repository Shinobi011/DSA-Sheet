// Time Complexity -> O(n)
// Space Somplexity -> O(1)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int cnt = 0;
        int val = 0;

        // Boyer-Moore Voting Algorithm 
        for (int num : nums) {
            if (cnt == 0) {
                val = num;
            }
            cnt += (num == val) ? 1 : -1;
        }

        return val;
    }
};