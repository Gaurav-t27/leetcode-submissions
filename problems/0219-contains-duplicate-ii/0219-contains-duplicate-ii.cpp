class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return false;
        unordered_map<int,int> um;

        for(int i=0;i<n;i++) {
            int num = nums[i];

            auto [it, ins] = um.try_emplace(num, i);
            if(!ins) {
                if(i - it->second <= k) {
                    return true;
                }
                it->second = i;

            }
        }
        return false;
    }
};