// Time Complexity -> O(nlogn)+O(n!⋅n)=O(n!⋅n)
// Space Somplexity ->  O(n⋅n!)

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used, current, results);
        return results;
    }
    
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& results) {
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, results);
            used[i] = false;
            current.pop_back();
        }
    }
};
