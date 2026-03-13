class Solution {
    int solve(vector<int>& nums, int start, int end) {
        int prev2 = nums[start];
        int prev1 = std::max(nums[start],nums[start+1]);

        for(int i = start+2; i<end; i++) {
            int curr = std::max(prev1, nums[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return std::max(nums[0], nums[1]);

        int s1 = solve(nums, 0, n-1);
        int s2 = solve(nums, 1, n);

        return std::max(s1,s2);
    }
};