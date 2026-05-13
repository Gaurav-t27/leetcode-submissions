class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        if(n==0) return n;

        int low=0;
        for(int high=0;high<n;high++) {
            if(nums[high] != val) {
                nums[low] = nums[high];
                low++;
            }
        }

        return low;
    }
};