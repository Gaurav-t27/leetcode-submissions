class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n=nums.size();

        unordered_map<int,int> hm;
        hm.insert(make_pair(nums[0],0));
        for(int i=1;i<n;++i)
        {
            int diff = target - nums[i];
            auto it = hm.find(diff);
            if( it != hm.end())
            {
                res={it->second, i};
                return res;
            }
            else
            {
                hm.insert(make_pair(nums[i], i));
            }
        }
        return res;
    }
};