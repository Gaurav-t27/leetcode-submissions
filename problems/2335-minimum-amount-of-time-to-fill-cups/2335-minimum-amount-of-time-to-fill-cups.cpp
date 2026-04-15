class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        std::priority_queue<int> pq;
        for(int i: amount) {
            if(i>0) pq.push(i);
        }

        int count = 0;
        while(!pq.empty()) {
            if(pq.size() > 1) {
                int first = pq.top(); pq.pop();
                int second = pq.top(); pq.pop();
                first--; second--;
                if(first>0) pq.push(first);
                if(second>0) pq.push(second);
                count++;
            } else {
                int last = pq.top(); pq.pop();
                count += last;
            }
        }
        return count;
    }
};