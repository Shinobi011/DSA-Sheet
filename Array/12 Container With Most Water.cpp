// Time Complexity -> O(n)
// Space Complexity -> O(1)
class Solution {
public:
 int maxArea(vector<int>& height) {
    int max_water = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        int current_area = width * current_height;
        max_water = max(max_water, current_area);
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_water;
}
};