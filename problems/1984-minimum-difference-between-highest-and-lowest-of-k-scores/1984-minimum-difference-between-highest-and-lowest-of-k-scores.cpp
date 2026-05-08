class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < k || k==1) return 0;

        sort(nums.begin(), nums.end());
        int low = 0;
        int min_diff = INT_MAX;
        for(int high = k-1;high<n;high++) {
            int diff = nums[high]-nums[low];
            min_diff = min(diff, min_diff);
            low++;
        }
        return min_diff;
    }
};