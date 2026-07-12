class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int col = board[0].size();
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j< col; j++) {
               if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
            return false;
        }
        bool dfs(vector<vector<char>>& board, int i, int j, int idx, string& word) {
    if (idx == word.length()) return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, i+1, j, idx+1, word) ||
                 dfs(board, i-1, j, idx+1, word) ||
                 dfs(board, i, j+1, idx+1, word) ||
                 dfs(board, i, j-1, idx+1, word);

    board[i][j] = temp;
    return found;
}
};