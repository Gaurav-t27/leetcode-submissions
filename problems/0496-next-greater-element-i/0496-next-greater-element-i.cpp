class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> um;
        stack<int> s;
        for(int num: nums2) {
            while(!s.empty() && num > s.top()) {
                um[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> res;
        for(int num:nums1) {
            if(um.find(num) != um.end()) {
                res.push_back(um[num]);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};