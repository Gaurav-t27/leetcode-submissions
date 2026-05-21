class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int> freq(26,0);

        for(auto c: tasks) {
            freq[c-'A']++;
        }
        
        priority_queue<int> pq;
        for(auto f:freq) {
            if(f>0) pq.push(f);
        }
        queue<pair<int,int>> cooling_q;

        int time=0;
        while(!pq.empty() || !cooling_q.empty()) {
            time++;
            if(!pq.empty()) {
                int count = pq.top()-1;
                pq.pop();
                if(count>0) {
                    cooling_q.push({count, time+n});
                }
            }

            if(!cooling_q.empty() && cooling_q.front().second == time) {
                pq.push(cooling_q.front().first);
                cooling_q.pop();
            }
        }
        return time;
    }
};