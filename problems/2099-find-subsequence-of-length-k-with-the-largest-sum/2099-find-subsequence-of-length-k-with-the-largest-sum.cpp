class Solution {
    using pii = std::pair<int,int>;
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        std::priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<nums.size();i++) {
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }
        vector<pii> top(k);
        for(int i=0;i<k;i++) {
            top[i] = pq.top(); 
            pq.pop();
        }
        std::sort(top.begin(),top.end(),[](const pii& a, const pii& b) {
            return a.second < b.second;
        });

        vector<int> res(k);
        for(int i=0;i<k;i++) {
            res[i] = top[i].first;
        }
        return res;
    }
};