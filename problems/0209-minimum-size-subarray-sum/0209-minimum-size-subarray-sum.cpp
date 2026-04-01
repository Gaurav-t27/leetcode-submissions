class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int min_len = INT_MAX;
        int cur_sum = 0;
        int left = 0;

        for(int right = 0; right< nums.size(); right++) {
            cur_sum = cur_sum + nums[right];

            while(cur_sum>=target) {
                min_len = std::min(min_len, right-left+1);

                cur_sum = cur_sum - nums[left];
                left++;
            }
        }

        return min_len == INT_MAX ? 0: min_len;
    }
};