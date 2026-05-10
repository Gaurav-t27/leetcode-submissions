class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_count = 0;
        for(int low = 0;low<n;low++) {
            if(nums[low]%2 == 0 && nums[low] <= threshold) {
                int high = low + 1;
                while(high < n && nums[high] <= threshold && (nums[high]%2 != nums[high-1]%2))
                    high++;

                max_count = max(max_count, high-low);
                low = high-1;
            }
        }
        return max_count;
    }
};