class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool find(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (idx == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '$')
            return false;

        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (int k = 0; k < 4; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];

            if (find(board, word, new_i, new_j, idx + 1)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};