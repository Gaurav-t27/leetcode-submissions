class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentSum = accumulate(nums.begin(),nums.begin()+k,0.0);
        double maxSum = currentSum;

        for(int i=k;i<nums.size();i++) {
            currentSum += nums[i] - nums[i-k];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum/k;
    }
};