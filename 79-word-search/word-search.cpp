class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& visited, vector<vector<char>>& board) {
        return (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && visited[row][col] == 0);
    }

    void solve(vector<vector<char>>& board, string& word, vector<vector<char>>& visited, int row, int col, int index, bool& ans) {
        if (index == word.length()) {
            ans = true;
            return;
        }
        if (!isSafe(row, col, visited, board) || board[row][col] != word[index]) {
            return;
        }

        // Mark the cell as visited
        visited[row][col] = 1;

        // Try all four directions (right, down, left, up)
        solve(board, word, visited, row, col + 1, index + 1, ans);  // right
        solve(board, word, visited, row + 1, col, index + 1, ans);  // down
        solve(board, word, visited, row, col - 1, index + 1, ans);  // left
        solve(board, word, visited, row - 1, col, index + 1, ans);  // up

        // Backtrack: Unmark the cell as visited
        visited[row][col] = 0;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        vector<vector<char>> visited(m, vector<char>(n, 0));

        // Try to start from every cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    solve(board, word, visited, i, j, 0, ans);
                    if (ans) return true;
                }
            }
        }
        return ans;
    }
};
