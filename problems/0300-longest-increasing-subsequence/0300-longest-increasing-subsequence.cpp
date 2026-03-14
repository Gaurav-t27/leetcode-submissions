class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;

        for(auto num:nums) {
            auto it = std::lower_bound(tail.begin(),tail.end(),num);

            if(it == tail.end()) {
                tail.push_back(num);
            } else {
                *it = num;
            }
        }
        return tail.size();
    }
};