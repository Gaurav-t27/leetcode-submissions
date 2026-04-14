class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::priority_queue<int, vector<int>,greater<>> pq;

        for(int i:nums) {
            pq.push(i);
            if(pq.size()>2) pq.pop();
        }
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        return(a-1) * (b-1);
    }
};