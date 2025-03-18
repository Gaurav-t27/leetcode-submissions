class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hs;
        if(nums.empty())
            return false;
        hs.insert(nums[0]);

        for(int i=1;i<nums.size();++i)
        {
            if(hs.find(nums[i]) != hs.end())
                return true;
            else
            {
                hs.insert(nums[i]);
            }
        }
        return false;
    }
};