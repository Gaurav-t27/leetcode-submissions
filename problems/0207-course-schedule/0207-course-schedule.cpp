class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);

        for (const auto& pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
        }

        for (int u = 0;u < numCourses;u++)
        {
            for (int v : adj[u])
            {
                inDeg[v]++;
            }
        }
        queue<int> q;
        for (int u = 0;u < numCourses;u++)
        {
            if (inDeg[u] == 0)
                q.push(u);
        }

        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            count++;
            for (const auto& nb : adj[u])
            {
                inDeg[nb]--;
                if (inDeg[nb] == 0)
                {
                    q.push(nb);
                }
            }
        }

        return numCourses == count;
    }
};