class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int start = 0, end = 0, temp_start = 0;

        for(int i=1;i<nums.size();i++) {
            if(nums[i] > curr_sum + nums[i]) {
                curr_sum = nums[i];
                temp_start = i;
            } else {
                curr_sum = curr_sum + nums[i];
            }

            if(curr_sum > max_sum) {
                max_sum = curr_sum;
                start = temp_start;
                end = i;
            }
        }
        return max_sum;
    }
};