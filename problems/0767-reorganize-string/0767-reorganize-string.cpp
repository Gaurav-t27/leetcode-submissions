class Solution {
    struct comparator {
        bool operator()(const pair<int,char>& p1, const pair<int,char>& p2) const {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        }
    };
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c:s) {
            freq[c-'a']++;
        }

        priority_queue<pair<int,char>, vector<pair<int,char>>, comparator> pq;
        int n = s.size();
        for(int i=0;i<26;i++) {
            if(freq[i] > (n+1)/2) return "";
            if(freq[i]>0) pq.push({freq[i], i+'a'});
        }

        string res = "";
        while(pq.size()>=2) {
            auto [f1,c1] = pq.top();pq.pop();
            auto [f2,c2] = pq.top();pq.pop();

            res+=c1;
            res+=c2;

            if(f1-1>0) pq.push({f1-1, c1});
            if(f2-1>0) pq.push({f2-1, c2});
            
        }

        if(!pq.empty())
            res += pq.top().second;
        return res;
    }
};