class Solution {
public:

     bool find(vector<vector<char>>& board, int i, int j, int index, string& word) {

        if (index == word.size()) return true;

        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() 
            || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '@';

        bool pick = 
            find(board, i - 1, j, index + 1, word) ||  // up
            find(board, i + 1, j, index + 1, word) ||  // down
            find(board, i, j - 1, index + 1, word) ||  // left
            find(board, i, j + 1, index + 1, word);    // right

        board[i][j] = temp;

        return pick;
    }
    bool exist(vector<vector<char>>& board, string word) {
         vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};  // up, left, down, right

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }

        return false;
    }
};