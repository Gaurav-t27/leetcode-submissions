class Solution {
    using pii = std::pair<int, int>;
    struct Comparator {
        bool operator()(const pii& p1, const pii& p2) {
            if(p1.first != p2.first) {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<pii, vector<pii>, Comparator> pq;
        int m = mat.size();
        int n = mat[0].size();
        for(int r=0;r<m;r++) {
            int rowSum = 0;
            for(int c=0;c<n;c++) {
                rowSum += mat[r][c];
            }
            pq.push({rowSum, r});
            if(pq.size() > k) pq.pop();
        }
        std::vector<int> res(k);
        for(int i=k-1;i>=0;i--) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};