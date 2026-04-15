class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        std::set<int> uniquePositives;
        for(int i: nums) {
            if(i>0) uniquePositives.insert(i);
        }
        return uniquePositives.size();
    }
};