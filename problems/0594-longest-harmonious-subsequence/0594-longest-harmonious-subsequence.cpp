class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int low=0, high=0;
        int maxCount = 0;
        
        for(int high=0;high<n;high++) {
            while(nums[high]-nums[low] > 1) {
                low++;
            }

            if(nums[high]-nums[low] == 1) {
                maxCount = max(maxCount, high-low+1);
            }
        }
        return maxCount;
    }
};