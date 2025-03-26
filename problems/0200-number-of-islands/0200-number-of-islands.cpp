class Solution {
public:
    int island_bfs(pair<int, int> p, const vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if (grid.empty())
            return 0;
        
        int R = grid.size(), C = grid[0].size();
        queue<pair<int, int>> q;
        q.push(p);
        visited[p.first][p.second] = true;

        while (!q.empty())
        {
            pair<int, int> p1 = q.front();
            q.pop();

            int r = p1.first;
            int c = p1.second;

            int right = c + 1, left = c - 1, top = r - 1, bottom = r + 1;
            if (right >= 0 && right < C && grid[r][right] == '1' && !visited[r][right])
            {
                q.push({ r,right });
                visited[r][right] = true;
            }
            if (left >= 0 && left < C && grid[r][left] == '1' && !visited[r][left])
            {
                q.push({ r,left });
                visited[r][left] = true;
            }
            if (bottom >= 0 && bottom < R && grid[bottom][c] == '1' && !visited[bottom][c])
            {
                q.push({ bottom,c });
                visited[bottom][c] = true;
            }
            if (top >= 0 && top < R && grid[top][c] == '1' && !visited[top][c])
            {
                q.push({ top,c });
                visited[top][c] = true;
            }
                
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int count = 0;

        for (int r = 0;r < R;r++)
        {
            for (int c = 0;c < C;c++)
            {
                if (grid[r][c] == '1' && !visited[r][c])
                {
                    count += island_bfs({ r,c }, grid, visited);
                }
            }
        }
        return count;
    }
};