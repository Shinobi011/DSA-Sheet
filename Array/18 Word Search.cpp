// Time Complexity  -> O(m * n * (4^l)
// Space Complexity -> O(l)
// l -> length of the Word
// m -> no. of rows
// n -> no. of cols
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int m = board.size();
        int n = board[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k]) return false;
        if (k == word.length() - 1) return true;
        
        char temp = board[i][j];
        board[i][j] = ' '; // mark as visited
        
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);
        
        board[i][j] = temp; // backtrack
        return found;
    }
};