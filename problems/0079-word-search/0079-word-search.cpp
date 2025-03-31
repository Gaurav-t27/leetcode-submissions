class Solution {
    int R, C;
    vector<vector<bool>> visited;
public:
    bool dfs_board(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if (i == word.length())
        {
            return true;
        }
        if (r < 0 || c < 0 || r >= R || c >= C|| visited[r][c]|| word[i] != board[r][c])
            return false;


        visited[r][c] = true;

        bool found = dfs_board(board, word, r, c + 1, i + 1)||
        dfs_board(board, word, r, c - 1, i + 1)||
        dfs_board(board, word, r + 1, c, i + 1)||
        dfs_board(board, word, r - 1, c, i + 1);

        visited[r][c] = false;
        
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        R = board.size();
        C = board[0].size();
        visited.resize(R, vector<bool>(C, false));

        for (int r = 0;r < R;r++)
        {
            for (int c = 0;c < C;c++)
            {  
                if(dfs_board(board, word, r, c, 0))
                {
                    return true;
                }

            }
        }
        return false;
    }
};