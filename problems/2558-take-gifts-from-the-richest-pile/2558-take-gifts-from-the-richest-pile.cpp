class Solution {
public:
    
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while(k-- && !pq.empty()) {
            int t = pq.top();
            pq.pop();
            pq.push(sqrt(t));
        }
        long long res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};