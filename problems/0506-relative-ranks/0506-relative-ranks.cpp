class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::priority_queue<pair<int,int>> pq;
        int n=score.size();
        vector<string> res(n);
        int rank=1;

        for(int i=0;i<n;i++) {
            pq.push({score[i],i});
        }
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            if(rank == 1)
                res[idx] = "Gold Medal";
            else if(rank == 2)
                res[idx] = "Silver Medal";
            else if(rank == 3)
                res[idx] = "Bronze Medal";
            else
                res[idx] = std::to_string(rank);

            rank++;
        }
        return res;
    }
};