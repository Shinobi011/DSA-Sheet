// Time Complexity -> O(m*n)
// Space Complexity -> O(m×n) for storing the result
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int left =0, right = cols-1, top =0, bottom = rows -1;

        while(left <= right && top <= bottom){
            // travel from left to right
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            ++top;
            
            // travel from top to bottom
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            --right;

            // travel from right to left, if we still have rows
            if(top <= bottom){
                for(int i = right; i >= left; --i){
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            if(left <= right){
                for(int i = bottom; i >= top; --i){
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return result;    
    }
};