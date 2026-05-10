class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k % n;
        std::rotate(nums.rbegin(), nums.rbegin()+k, nums.rend());
    }
};