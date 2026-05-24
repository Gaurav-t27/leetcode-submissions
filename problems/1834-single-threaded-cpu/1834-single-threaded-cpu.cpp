class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<tuple<int,int,int>> sorted(n);
        for(int i=0;i<n;i++) {
            sorted[i] = {tasks[i][0],tasks[i][1],i};
        }
        sort(sorted.begin(), sorted.end());
        using pii=pair<int,int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        long timer = 0;
        vector<int> res;
        int i = 0;
        while(res.size()<n){
            while(i<n and get<0>(sorted[i]) <= timer) {
                pq.push({get<1>(sorted[i]), get<2>(sorted[i])});
                i++;
            }

            if(pq.empty()) {
                timer = get<0>(sorted[i]);
                continue;
            }

            auto item = pq.top(); pq.pop();
            timer += item.first;
            res.push_back(item.second);
        }
        return res;
    }
};