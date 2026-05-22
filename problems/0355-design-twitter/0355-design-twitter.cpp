class Twitter {
    unordered_map<int, unordered_set<int>> follow_map;
    unordered_map<int,vector<pair<int,int>>> tweets_map;
    int timer;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets_map[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;

        follow_map[userId].insert(userId);

        for(auto followee: follow_map[userId]) {
            const auto& tweets = tweets_map[followee];
            int n = tweets.size();

            if(n>0) {
                pq.push({tweets[n-1].first, tweets[n-1].second, followee, n-1 });
            }
        }

        vector<int> feeds;
        while(!pq.empty() && feeds.size() < 10) {
            auto item = pq.top(); pq.pop();
            int followee = item[2];
            int idx = item[3];

            if(idx > 0)
                pq.push({tweets_map[followee][idx-1].first, tweets_map[followee][idx-1].second, followee, idx-1});
            
            feeds.push_back(item[1]);
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */