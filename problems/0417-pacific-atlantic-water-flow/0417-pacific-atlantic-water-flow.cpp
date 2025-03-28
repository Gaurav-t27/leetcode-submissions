class Solution {
public:
    void bfs_pac(queue<pair<int, int>>& q, 
        vector<vector<bool>>& visited, 
        const vector<vector<int>>& heights, 
        const vector<pair<int, int>> dir)
    {
        int R = heights.size();
        int C = heights[0].size();
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            

            int r = p.first, c = p.second;
            visited[r][c] = true;
            for (auto d : dir)
            {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < R &&
                    nc >= 0 && nc < C &&
                    heights[nr][nc] >= heights[r][c] &&
                    !visited[nr][nc])
                {
                    q.push({ nr,nc });
                }
            }

        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> islands;
        if (heights.empty())
            return islands;
        int R = heights.size(), C = heights[0].size();

        vector<vector<bool>> pacVisited(R, vector<bool>(C, false));
        vector<vector<bool>> atlVisited(R, vector<bool>(C, false));

        queue<pair<int, int>> pacQueue, atlQueue;

        for (int c = 0;c < C;c++)
        {
            pacQueue.push({ 0, c });
            atlQueue.push({ R - 1,c });
        }
        for (int r = 0;r < R;r++)
        {
            pacQueue.push({ r,0 });
            atlQueue.push({ r,C - 1 });
        }
        vector<pair<int, int>> dir{ {1,0},{-1,0},{0,1},{0,-1} };

        bfs_pac(pacQueue, pacVisited, heights, dir);
        bfs_pac(atlQueue, atlVisited, heights, dir);

        for (int r = 0;r < R;r++)
        {
            for (int c = 0;c < C;c++)
            {
                if (pacVisited[r][c] && atlVisited[r][c])
                {
                    islands.push_back({ r,c });
                }
            }
        }
        return islands;
    }
};