class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());

        vector<int> res;
        res.reserve(nums.size());
        while(!pq.empty()) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            res.push_back(s);
            res.push_back(f);
        }
        return res;
    }
};