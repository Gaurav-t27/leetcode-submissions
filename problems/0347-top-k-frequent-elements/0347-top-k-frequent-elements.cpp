class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> um;

        for (auto e : nums)
        {
            um[e]++;
        }

        priority_queue<std::pair<int,int>> maxheap;
        for (auto e : um)
        {
            maxheap.push({ e.second,e.first });
        }

        vector<int> res;
        for (int i = 0;i < k && !maxheap.empty(); ++i)
        {
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }   
        return res;
    }
};