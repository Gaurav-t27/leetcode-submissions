class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> us;

        for(int i=0;i<n;i++) {
            if(us.find(nums[i])!=us.end()) return true;

            us.insert(nums[i]);
            if(us.size() > k) {
                us.erase(nums[i-k]);
            }
        }
        return false;
    }
};