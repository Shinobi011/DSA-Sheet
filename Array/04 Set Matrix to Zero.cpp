// T.C - O(m * n)
// S.C - O(m + n)
// Approach - 1

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> r;
        vector<int> c;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }

        // Set rows to zero
        for (int i = 0; i < r.size(); i++) {
            for (int k = 0; k < cols; k++) {
                matrix[r[i]][k] = 0;
            }
        }

        // Set columns to zero
        for (int l = 0; l < c.size(); l++) {
            for (int j = 0; j < rows; j++) {
                matrix[j][c[l]] = 0;
            }
        }
    }
};


// T.C - O(m * n)
// S.C - O(1)
// Approach - 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Set markers in the first row and first column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Replace inner matrix
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Last remaining checks
        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};