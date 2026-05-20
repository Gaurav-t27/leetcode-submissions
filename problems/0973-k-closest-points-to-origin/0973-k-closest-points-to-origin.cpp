class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using pii = pair<int,int>;
        priority_queue<pii> pq;

        for(int i=0;i<points.size();i++) {
            int dist = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dist,i});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            pii p = pq.top();
            pq.pop();
            res.push_back(points[p.second]);
        }
        return res;
    }
};