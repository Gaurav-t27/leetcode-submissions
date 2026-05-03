class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int low = 0, high = 1;
        while(high<n) {
            if(nums[low] != nums[high]) {
                low++;
                nums[low] = nums[high];
            }
            high++;
        }
        return low+1;
    }
};