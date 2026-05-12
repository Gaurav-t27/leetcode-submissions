class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> um;

        for(int i=0;i<n;i++) {
            if(um.find(nums[i]) != um.end()) return true;
            um.insert(nums[i]);
        }
        return false;
    }
};