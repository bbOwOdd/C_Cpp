class Twitter {
public:
    unordered_map<int, unordered_set<int>> followees;
    vector<pair<int, int>> posts;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> ans;
        for(int i = posts.size() - 1; i >= 0 && count < 10; i--){
            if(posts[i].first == userId || followees[userId].contains(posts[i].first)){
                ans.push_back(posts[i].second);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
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
